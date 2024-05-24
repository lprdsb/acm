# ======================================================================
# DESCRIPTION: This file contains the world class, which is responsible
#              for everything game related.
#
# NOTES:       - Don't make changes to this file.
# ======================================================================

from Agent import Agent
# from ManualAI import ManualAI
# from RandomAI import RandomAI
# from MyAI import MyAI
import random

class World():
    
    # Tile Structure
    class __Tile:
        pit    = False
        wumpus = False
        gold   = False
        breeze = False
        stench = False
    
    # ===============================================================
    # =                 Constructor
    # ===============================================================   
    
    def __init__ ( self, MyAI = None, file = None ):
        
        # Agent Initialization
        self.__goldLooted   = False
        self.__arrowNum     = 3
        self.__bump         = False
        self.__scream       = False
        self.__score        = 0
        self.__agentX       = 0
        self.__agentY       = 0
        self.__lastAction   = Agent.Action.CLIMB

        

        self.__agent = MyAI()
            
        if file != None:
            self.__colDimension, self.__rowDimension = [int(x) for x in next(file).split()]
            self.__board = [[self.__Tile() for j in range(self.__rowDimension)] for i in range(self.__colDimension)]
            self.__addFeatures(file)
        else:
            self.__colDimension = 10
            self.__rowDimension = 10
            self.__board = [[self.__Tile() for j in range(self.__colDimension)] for i in range(self.__rowDimension)]
            self.__addFeatures()
    
    # ===============================================================
    # =                 Engine Function
    # ===============================================================   
    
    def run ( self ):
        while self.__score >= -1000:
            self.__printWorldInfo()
                
            # Get the move
            action = self.__agent.getAction (           self.__agentX,self.__agentY,
														self.__board[self.__agentX][self.__agentY].stench,
														self.__board[self.__agentX][self.__agentY].breeze,
														self.__board[self.__agentX][self.__agentY].gold,
														self.__bump,
														self.__scream
													   )
            # Make the move
            self.__score -= 1
            self.__bump   = False
            self.__scream = False
            
            if action == Agent.Action.LEFT:
                if self.__agentX-1 >= 0:
                    self.__agentX -= 1
                else:
                    self.__bump = True
                    
            elif action == Agent.Action.RIGHT:
                if self.__agentX+1 < self.__colDimension:
                    self.__agentX += 1
                else:
                    self.__bump = True
                    
            elif action == Agent.Action.FORWARD:
                if self.__agentY+1 < self.__rowDimension:
                    self.__agentY += 1
                else:
                    self.__bump = True

            elif action == Agent.Action.BACKWARD:
                if self.__agentY-1 >= 0:
                    self.__agentY -= 1
                else:
                    self.__bump = True  

            elif action == Agent.Action.SHOOT:
                if self.__arrowNum > 0:
                    self.__arrowNum -= 1
                    self.__score -= 10
                # if the agent has no arrow, it will do nothing
                else:
                    action = Agent.Action.CLIMB

            elif action == Agent.Action.GRAB:
                if self.__board[self.__agentX][self.__agentY].gold:
                    self.__board[self.__agentX][self.__agentY].gold = False
                    self.__goldLooted = True
                    
            elif action == Agent.Action.CLIMB:
                if self.__agentX == self.__colDimension-1 and self.__agentY == self.__rowDimension-1:
                    if self.__goldLooted:
                        self.__score += 1000
                    return self.__score

            # Diving into the pit or not
            if self.__board[self.__agentX][self.__agentY].pit:
                self.__score -= 1000
                return self.__score

            # Killed by the Wumpus or not
            if self.__board[self.__agentX][self.__agentY].wumpus:
                # Killed by the Wumpus
                if self.__lastAction != Agent.Action.SHOOT:
                    self.__score -= 1000
                    return self.__score

                # Kill the Wumpus
                self.__board[self.__agentX][self.__agentY].wumpus = False
                self.__board[self.__agentX][self.__agentY].stench = True
                self.__scream = True

            self.__lastAction = action

        return self.__score
        
    # ===============================================================
    # =             World Generation Functions
    # ===============================================================
    
    def __addFeatures ( self, file = None ):
        if file == None:
            # Generate pits and wumpus
            points = self.generate_unique_points(7)

            points_pit = points[:3]
            points_wumpus = points[3:6]
            points_gold = points[6:]

            for point in points_pit:
                self.__addPit(point[0], point[1])

            for point in points_wumpus:
                self.__addWumpus(point[0], point[1])

            for point in points_gold:
                self.__addGold(point[0], point[1])
            
        else:
            # Add the Wumpus
            numOfWumpus = int(next(file))
            while numOfWumpus > 0:
                numOfWumpus -= 1
                c, r = [int(x) for x in next(file).split()]
                self.__addWumpus ( c, r )

            # Add the Pits
            numOfPits = int(next(file))
            while numOfPits > 0:
                numOfPits -= 1
                c, r = [int(x) for x in next(file).split()]
                self.__addPit ( c, r )
            
            # Add the Gold
            numOfGold = int(next(file))
            while numOfGold > 0:
                numOfGold -= 1
                c, r = [int(x) for x in next(file).split()]
                self.__addGold ( c, r )

            file.close()
    
    def __addPit ( self, c, r ):
        if self.__isInBounds(c, r):
            self.__board[c][r].pit = True
            self.__addBreeze ( c+1, r )
            self.__addBreeze ( c-1, r )
            self.__addBreeze ( c, r+1 )
            self.__addBreeze ( c, r-1 )
    
    def __addWumpus ( self, c, r ):
        if self.__isInBounds(c, r):
            self.__board[c][r].wumpus = True
            self.__addStench ( c+1, r )
            self.__addStench ( c-1, r )
            self.__addStench ( c, r+1 )
            self.__addStench ( c, r-1 )
    
    def __addGold ( self, c, r ):
        if self.__isInBounds(c, r):
            self.__board[c][r].gold = True
    
    def __addStench ( self, c, r ):
        if self.__isInBounds(c, r):
            self.__board[c][r].stench = True
    
    def __addBreeze ( self, c, r ):
        if self.__isInBounds(c, r):
            self.__board[c][r].breeze = True
    
    def __isInBounds ( self, c, r ):
        return c < self.__colDimension and r < self.__rowDimension and c >= 0 and r >= 0
    
    # ===============================================================
    # =             World Printing Functions
    # ===============================================================
    
    def __printWorldInfo ( self ):
        self.__printBoardInfo()
        self.__printAgentInfo()
    
    def __printBoardInfo ( self ):
        for r in range (self.__rowDimension-1, -1, -1):
            for c in range (self.__colDimension):
                self.__printTileInfo ( c, r )
            print("")
            print("")

    def __printTileInfo ( self, c, r ):
        tileString = ""
        
        if self.__board[c][r].pit:    tileString += "P"
        if self.__board[c][r].wumpus: tileString += "W"
        if self.__board[c][r].gold:   tileString += "G"
        if self.__board[c][r].breeze: tileString += "B"
        if self.__board[c][r].stench: tileString += "S"
        
        if self.__agentX == c and self.__agentY == r:
            tileString += "@"
        
        tileString += "."
        
        print(tileString.rjust(8), end="")
    
    def __printAgentInfo ( self ):
        print ( "Score: "   + str(self.__score) )
        print ( "AgentX: "  + str(self.__agentX) )
        print ( "AgentY: "  + str(self.__agentY) )
        self.__printPerceptInfo()
    
    

    def __printPerceptInfo ( self ):
        perceptString = "Percepts: "
        
        if self.__board[self.__agentX][self.__agentY].stench: perceptString += "Stench, "
        if self.__board[self.__agentX][self.__agentY].breeze: perceptString += "Breeze, "
        if self.__board[self.__agentX][self.__agentY].gold:   perceptString += "Glitter, "
        if self.__bump:                         perceptString += "Bump, "
        if self.__scream:                       perceptString += "Scream"
        
        if perceptString[-1] == ' 'and perceptString[-2] == ',':
            perceptString = perceptString[:-2]
        
        print(perceptString)
    
    # ===============================================================
    # =                 Helper Functions
    # ===============================================================
    
    def __randomInt ( self, limit ):
        return random.randrange(limit)

    def generate_unique_points(self, n):
        points = set()  
        while len(points) < n:
            x = random.randint(0, self.__colDimension-1)  
            y = random.randint(0, self.__rowDimension-1)  
            point = (x, y)
            points.add(point)
        
        return list(points) 

    def generate_unique_points(self, n):
        points = set()  
        # random.seed(114514)
        while len(points) < n:
            x = random.randint(0, self.__colDimension-1)  
            y = random.randint(0, self.__rowDimension-1)  
            point = (x, y)
            
            # Check if the point is too close to any existing point
            if all(abs(point[0] - existing_point[0]) + abs(point[1] - existing_point[1]) >= 3 for existing_point in points)  and point != (0,0) and point != (self.__colDimension-1, self.__rowDimension-1):
                points.add(point)
            
        return list(points)