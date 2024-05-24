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

class MyAI ( Agent ):

    def __init__ ( self ):
        # ======================================================================
        # YOUR CODE BEGINS
        # ======================================================================
        
        pass
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
        if glitter:
            return Agent.Action.GRAB
        # ======================================================================
        # YOUR CODE BEGINS
        # ======================================================================


        return Agent.Action.GRAB
        # ======================================================================
        # YOUR CODE ENDS
        # ======================================================================
    
    # ======================================================================
    # YOUR CODE BEGINS
    # ======================================================================

    
    # ======================================================================
    # YOUR CODE ENDS
    # ======================================================================