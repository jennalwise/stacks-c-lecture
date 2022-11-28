## Task 1: Deciding On & Defending Use of Stack

Write down whether a stack is appropriate for each of the following tasks, and indicate why or why not:

<ol type = "a">
    <li> 
    A word-processing program must remember a line of up to 80 characters. Pressing the Backspace key deletes the previous character, and pressing Ctrl+Backspace deletes the entire line. Users must be able to undo deletion operations.
    </li> 
    <li>
    Customers must wait one to three months for delivery of their new cars. The dealer creates a list to determine the "fair" order in which customers should get their cars; the list is prepared in the order in which customers places their requests for a new car.
    </li>
    <li>
    You're required to search downward in a pile of magazines to locate the issue for last January. Each magazine was placed on the pile as soon as it was received.
    </li>
    <li>
    A programming team accepts jobs and prioritizes them on the basis of urgency.
    </li>
    <li>
    A line forms at a bus stop.
    </li>
</ol>

## Answers

<ol type = "a">
    <li> 
    When deleting a character or line, the characters can be pushed onto a stack and so forth as more deletion happens. When a user wants to undo, they want to undo the previous/last deletion. So, the previously deleted characters can be popped off the stack and returned to the working document. That is, Stacks are natural here, where First-In-Last-Out works great for undo operations.
    </li> 
    <li>
    Cars must be delivered in order by which customers placed their request, this is a First-In-First-Out strategy. So, Stacks do not work here as they support a First-In-Last-Out strategy.
    </li>
    <li>
    Since we are required to search downward in a pile of magazines to locate the issue for last January and each magazine was placed on the pile as soon as it was received, we expect last January to be placed first as it is received first and last February second, and so forth for each month until present time. As a result, the current month's magazine is on the top and January is on the bottom (so we have to search downward). That is, the magazines are ordered First-In-Last-Out and Stacks are very appropriate.
    </li>
    <li>
    The programming team wants to organize jobs by priority of urgency, so whichever job is the most urgent is tackled by the programming team first. This job could have entered the system recently or have been there a while (not the last to enter), so a First-In-Last-Out strategy from Stacks is not appropriate.
    </li>
    <li>
    At the bus stop people line up from first to last while waiting for the bus. When the bus arrives the first person who lined up will get on and so forth. This is a First-In-First-Out strategy, so a Stack, which is First-In-Last-Out is not appropriate.
    </li>
</ol>