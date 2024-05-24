# ======================================================================
# DESCRIPTION: This file is the entry point for the program. The main
#              function serves a couple purposes: (1) It is the
#              interface with the command line. (2) It reads the files,
#              creates the World object, and passes that all the
#              information necessary. (3) It is in charge of outputing
#              information.
#
# NOTES:       - Syntax:
#
#                   Wumpus_World [Options] [InputFile] [OutputFile]
#
#                  Options:
#                      -a the agent to use.(e.g. XJY_2022310166)
#                      -f treats the InputFile as a folder containing
#                         worlds. This will trigger the program to
#                         display the average score and standard
#                         deviation instead of a single score. InputFile
#                         must be entered with this option.
#
#                  InputFile: A path to a valid Wumpus World File, or
#                             folder with -f. This is optional unless
#                             used with -f or OutputFile.
#
#
#              - Don't make changes to this file.
# ======================================================================

import sys
import os
import math
import importlib
from World import World
from YJR_2022111475 import MyAI

def main ( ):
    args = sys.argv
    
    if len(args) == 1:

        # Select a random world 
        world = World(MyAI)

        # Select a specific world
        # world = World( MyAI, file = open ( "worlds/world1.txt", 'r',newline="\n" ) )

        score = world.run()
        print ("Your agent scored: " + str(score))
        return

    # Important Variables
    student    = ""
    folder     = False
    worldFile  = ""
    outputFile = "studentScores.txt"
    print (args)
    
    index_parse = 1
    # Parse Command Line Arguments
    while 2*index_parse-1 < len(args):
        token = args[2*index_parse-1]
        if token[0] == '-':
            if token == '-a':
                if len(args) < 1 + 2*index_parse:
                    print ( "[ERROR] No agent specified." )
                    return
                student = args[2*index_parse]
            elif token == '-f':
                folder = True
                if len(args) < 1 + 2*index_parse:
                    print ( "[ERROR] No folder specified." )
                    return
                worldFile = args[2*index_parse]
            else:
                print ( "[ERROR] Invalid option." )
                return
            index_parse += 1

    # load agent
    if student != "":
        try:
            studentAI = importlib.import_module(student).MyAI
        except:
            print ( "[ERROR] Failed to import agent." )
            return

    if worldFile == "":
        if folder:
            print ( "[ERROR] No folder specified running on a random world." )
            return
        world = World(studentAI)
        score = world.run()
        print ( "The agent scored: " + str(score) )
        return
            
    if folder:
        listOfWorlds = None
        
        try:
            listOfWorlds = os.listdir ( worldFile )
        except:
            print ( "[ERROR] Failed to open directory." )
            return

        numOfScores = 0
        sumOfScores = 0

        for file in listOfWorlds:

            score = None
            try:
                newLineDelim = "\n"
                if "\r\n".encode() in open(worldFile + "/" + file,"rb").read():
                    newLineDelim = "\r\n"
                world = World(studentAI, file =  open ( worldFile + "/" + file, 'r', newline=newLineDelim ) )
                score = world.run()
                print ( "The agent scored: " + str(score) )
            except Exception:
                # tell the reason of the error in the console
                import traceback
                traceback.print_exc()


                numOfScores = 0
                sumOfScores = 0
                break

            numOfScores += 1
            sumOfScores += score

        avg = None
        std_dev = None
        
        if numOfScores != 0:
            avg = sumOfScores / numOfScores
        else:
            avg = float('nan')

        if outputFile == "":
            print ( "The agent's average score: " + str(avg) )
        else:
            outFile = open ( outputFile, 'a+' )
            outFile.write ( f"{student[-10:]} " + str(avg) + '\n' )
            outFile.close ( )

        return

main()
