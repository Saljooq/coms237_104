Name: Saljooq Altaf
Net ID: saltaf


Assignment 1.04


There were several new functions including initialize_pc, populate_heap, pop_player,push_player_node, kill_player, next_move and kill_all - to accomplish the task of initializing number of monsters with varying characteristics according to the specs. Details are found below.

Four new structs are created as well, including PC, NPC, player_node and player_node_heap. PC and NPC contain limited information on PC and monsters. player_node contain interesting details about all player, including if 'this' node is PC or not, pointer of PC/NPC and concerning details like when_initiated, next_turn etc. The heap is implemented as a linked_list that pop's based on the priorities in the specs (next_turn, when_initiated).

Additionally there is a 2d array 'grid_players' contains all the player's nodes.

1. initialize_pc - this is used to take a pc struct's pointer and create a node and place it in random spot.
2. distant_from_pc - is used to make sure that monsters initialise away from PC.
3. initialize_players - used to create all the npc's as per the specs.
4. populate_heap - populates our heap with all the players.
5. push_player_node - simple method to push different players onto the heap.
6. pop_player - This is used to select a node in the heap based on the specs (lowest -> next_turn, when_initiated)
7. next_move - This is used to figure out what to do with the node selected with pop_player.
8. kill_player - Used to kill a selected player.
9. kill_all - This is a clean-up mechanism that makes sure all remaining players(malloc'd) are freed.


Additionally, there are some additional lines in main that takes care of getting a '--nummon' switch, with default being 10.
