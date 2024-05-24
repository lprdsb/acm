# ======================================================================
# DESCRIPTION: This file contains your agent class, which you will
#              implement. You are responsible for implementing the
#              'getAction' function and any helper methods you feel you
#              need.
#
# NOTES:       - If you are having trouble understanding how the shell
#                works, look at the other parts of the code, as well as
#                the documentation.
#
#              - You are only allowed to make changes to this portion of
#                the code. Any changes to other portions of the code will
#                be lost when the tournament runs your code.
# ======================================================================

from Agent import Agent
from abc import ABCMeta, abstractmethod
from enum import Enum
import random
from collections import Counter

class MyAI ( Agent ):
    class State:
        def __init__(self, AgentX, AgentY, stench, breeze, glitter, bump, scream, opt):
            self.AgentX = AgentX
            self.AgentY = AgentY
            self.stench = stench
            self.breeze = breeze
            self.glitter = glitter
            self.bump = bump
            self.scream = scream
            self.opt = opt
    

    def __init__ ( self ):
        # ======================================================================
        # YOUR CODE BEGINS
        # ======================================================================
        self.visit = [[False for y in range(10)] for x in range(10)]
        self.dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        self.state = [[self.State(x, y, 0, 0, 0, 0, 0, 0) for y in range(10)] for x in range(10)]
        self.stack = []
        print(self.visit)
        # ======================================================================
        # YOUR CODE ENDS
        # ======================================================================
   


    def getAction( self, AgentX, AgentY, stench, breeze, glitter, bump, scream ):
        '''
        Description of inputs:
                AgentX:     X location of the agent
                AgentY:     Y location of the agent
                stench:     boolean, is there a stench
                breeze:     boolean, is there a breeze
                glitter:    boolean, is there gold
                bump:       boolean, did you bump into a wall
                scream:     boolean, did the wumpus scream (the wumpus is killed by your arrow)
        '''
        def check(x, y):
            return 0 <= x <= 9 and 0 <= y <= 9 and not self.visit[x][y]
        
        def backward():
            self.stack.pop()
            print(self.stack[-1], (AgentX, AgentY))
            # exit(0)
            if self.stack[-1][0] + 1 == AgentX:
                self.stack.pop()
                return Agent.Action.LEFT
            if self.stack[-1][0] - 1 == AgentX:
                self.stack.pop()
                return Agent.Action.RIGHT
            if self.stack[-1][1] + 1 == AgentY:
                self.stack.pop()
                return Agent.Action.BACKWARD
            if self.stack[-1][1] - 1 == AgentY:
                self.stack.pop()
                return Agent.Action.FORWARD
            
        self.visit[AgentX][AgentY] = True
        self.stack.append([AgentX, AgentY])

        if glitter:
            self.stack.pop()
            return Agent.Action.GRAB

        if AgentX == 9 and AgentY == 9: return Agent.Action.CLIMB
        if (stench or breeze) and (AgentX != 1 or AgentY != 0):
            if stench: self.state[AgentX][AgentY].stench = 1
            if breeze: self.state[AgentX][AgentY].breeze = 1
            return backward()
        
        for i in range(self.state[AgentX][AgentY].opt, 4):
            tx = AgentX + self.dir[i][0]
            ty = AgentY + self.dir[i][1]
            self.state[AgentX][AgentY].opt += 1
            if check(tx, ty):
                if i == 0:
                    return Agent.Action.FORWARD
                if i == 1:
                    return Agent.Action.BACKWARD
                if i == 2:
                    return Agent.Action.RIGHT
                if i == 3:
                    return Agent.Action.LEFT
        
        return backward()
    #获得相邻房间
    
        

       
    
       
