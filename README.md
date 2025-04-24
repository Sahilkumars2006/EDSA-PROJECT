# SahilKumar
Assignment Question 8: Earthquake Rescue Robot Coordinator 
Scenario: You’re designing an Earthquake Rescue Robot Coordinator to deploy robots (e.g., "Scanner", "Digger", "Lift", "Light", "Drone") for disaster relief. The system uses:

●Mission Request System (Queue): Rescue tasks queue up from survivors.

●Urgent Task Handler (Stack): Critical tasks stack in LIFO order for immediate action.

●Rescue Log Unit (Array): Completed missions log into an array-based base (size: 6 slots). If full, the oldest is reported.

●Repair Tracker (Linked Lists):

○Damaged robots go to a singly linked list.

○Repaired robots move to a doubly linked list for inspection.

○High-priority robots cycle in a circular linked list for urgent redeployment.

Objective: Simulate rescue mission coordination, logging, and robot repair.
Tasks:

a) Mission and Urgency 

●Simulate 6 tasks (e.g., "Scanner", "Digger", "Lift", "Light", "Drone", "Cutter") arriving in a queue.

●Stack urgent tasks in LIFO order. Write pseudocode or an algorithm to:

○Enqueue all 6 tasks.

○Dequeue and push onto a stack.

○Pop to show action order.

●Creativity Bonus: Describe (in 2-3 sentences) why LIFO fits (e.g., "Cutter" last to clear debris safely).

b) Rescue Log Unit 

●Log missions in a 6-slot array.

●Simulate logging 8 missions (e.g., "Mis1", "Mis2", ..., "Mis8"). If full, report the oldest. Write pseudocode or an algorithm to:

○Insert the first 6 missions.

○Handle overflow for "Mis7" and "Mis8".

●Creativity Bonus: Suggest (in 2-3 sentences) a reason for reporting (e.g., survivor status updates).

c) Damaged Robot Tracker 

●"Digger" and "Drone" are damaged. Add to a singly linked list.

●Move "Digger" to a doubly linked list post-repair. Write pseudocode or an algorithm to:

○Insert "Digger" and "Drone".

○Delete "Digger" and insert it into the doubly linked list.

○Traverse forward and backward.

●Creativity Bonus: Propose (in 2-3 sentences) a damage and fix (e.g., "Digger’s arm crushed, rebuilt by techs").

d) Priority Redeployment 

●"Scanner" and "Lift" need urgent redeployment (e.g., trapped survivors). Add to a circular linked list. Write pseudocode or an algorithm to:

○Insert "Scanner" and "Lift".

○Traverse twice.

●Creativity Bonus: Invent (in 2-3 sentences) a redeployment tweak (e.g., "Lift gets a thermal camera").
