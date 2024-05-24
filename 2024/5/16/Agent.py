# ======================================================================
# DESCRIPTION: This file contains the abstract agent class, which
#              details the interface for a wumpus agent. The actuators
#              are listed in the 'Action' enum, while the sensors are
#              parameters to the abstract function 'getAction'. Any
#              agent will need to implement the getAction function,
#              which returns an Action for every turn in the game.
#
# NOTES:       - An agent is anything that can be viewed as perceiving
#                its environment through sensors and acting upon that
#                environment through actuators
#
#              - Throughout this project Agent and AI are
#                interchangeable
#
#              - Don't make changes to this file.
# ======================================================================

from abc import ABCMeta, abstractmethod
from enum import Enum

class Agent ( metaclass=ABCMeta ):

    # Actuators
    class Action ( Enum ):
        LEFT       = 1  
        RIGHT      = 2
        FORWARD    = 3
        BACKWARD   = 4
        SHOOT      = 5  # If you shoot before entering a room with the wumpus, you can kill it; otherwise, it will kill you
        GRAB       = 6  # If you enter a room with gold, you can grab the gold
        CLIMB      = 7  # If you arrive at (9,9), you can climb out

    @abstractmethod
    def getAction ( self,
    
        # Sensors
        stench,
        breeze,
        glitter,
        bump,
        scream
    ):
        pass