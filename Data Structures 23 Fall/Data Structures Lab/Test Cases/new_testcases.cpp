//
//NEW TEST CASES
//6
//SLF
//

#include <gtest/gtest.h>
#include "header.h"


//--------------------------------------------------------

///////Shift Task
TEST(displayY, shiftTask){
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Mehar", "Azam", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Muhammad","Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hashir","Ather", "Askari 4", "1/1/2003");
    taskSystem.addAssignee("Aroob","Saeed", "Askari 3", "23/3/2002");

    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");
    taskSystem.addTask(104, "complete assignment", 3, "A004");

    taskSystem.ShiftTask("A002", "A003");
    taskSystem.ShiftTask("A003", "A004");

    std::stringstream actualOutput1;
    taskSystem.AssigneeWithNoTask(actualOutput1);

    //The expected output
    std::string expectedOutput1 =
    "Name: Mehar Azam, Address: I6, DOB: 2/11/2003, Assignee ID: A001\n"
    "Name: Muhammad Hashim, Address: Dha phase 5, DOB: 11/2/2002, Assignee ID: A002\n"
    "Name: Hashir Ather, Address: Askari 4, DOB: 1/1/2003, Assignee ID: A003\n";

    std::stringstream actualOutput2;
    taskSystem.printTaskQueue(actualOutput2); //output should be displayed in order of highest to lowest priority

    //The expected output
    std::string expectedOutput2 =
    "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Aroob (A004)\n"
    "Task ID: 102, Description: Fix Bug in Module B, Priority: 2, Assignee: Aroob (A004)\n"
    "Task ID: 104, Description: complete assignment, Priority: 3, Assignee: Aroob (A004)\n"
                               ;

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput1.str(), expectedOutput1);
    ASSERT_EQ(actualOutput2.str(), expectedOutput2);

}


/////delete
TEST(displayY, delete1){
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Muhammad", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Muhammad","Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Muhammad","Ali", "Askari 14", "1/1/2003");


    taskSystem.DeleteAssignee("A003");

    taskSystem.addAssignee("Hussain", "Ali", "Lalazar", "20/1/2001");  //This should get A004

    taskSystem.DeleteAssignee("A004");
//
    taskSystem.addAssignee("Laraib", "Athar", "DHA 2", "11/2/2002"); //A005
    std::stringstream actualOutput;
    taskSystem.DisplayAssignee(actualOutput); //Dispay in order of IDs

    //The expected output
    cout<<actualOutput.str()<<endl;

    std::string expectedOutput =
    "Name: Muhammad Ali, Address: I8, DOB: 2/11/2001, Assignee ID: A001\n"
    "Name: Muhammad Shah, Address: Dha phase 1, DOB: 11/2/2002, Assignee ID: A002\n"
    "Name: Laraib Athar, Address: DHA 2, DOB: 11/2/2002, Assignee ID: A005\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}


////////////////Assignee tree printing
TEST(displayY, inorderAssignee){
    taskManagementSystem taskSystem;
    // auto assign unique IDs to each Assignee
    taskSystem.addAssignee("Shahnoor", "Ali", "I8", "2/11/2001");  //This should get A001
    taskSystem.addAssignee("Mehdi","Shah", "Dha phase 1", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hadi","Ali", "Askari 14", "1/1/2003");
    taskSystem.addAssignee("Zahra", "Rida", "I6", "2/10/2000");
    taskSystem.addAssignee("Mukhtar","Shah", "Dha phase 7", "1/2/2001");
    taskSystem.addAssignee("Hammad","Ali", "Askari 4", "1/10/2002");
    taskSystem.addAssignee("Meer","Shah", "Dha phase 2", "2/12/2001");
    taskSystem.addAssignee("Shahzaib","Ali", "Askari 2", "13/11/2002");

    taskSystem.DeleteAssignee("A007");
    std::stringstream actualOutput;
    taskSystem.AssigneeInOrder(actualOutput); //Dispay in order of IDs

    //The expected output
    std::string expectedOutput =
    "A001 (black)\n"
    "A002 (red)\n"
    "A003 (black)\n"
    "A004 (black)\n"
    "A005 (black)\n"
    "A006 (red)\n"
    "A008 (black)\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);

}



//////Updating priority
TEST(updatingY, second){
    taskManagementSystem taskSystem;
    taskSystem.addAssignee("Aaimlik", "Abbasi", "I6", "2/11/2003");  //This should get A001
    taskSystem.addAssignee("Amna","Hashim", "Dha phase 5", "11/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Huma","Ather", "Askari 4", "1/1/2003");
    taskSystem.addAssignee("Ali","Shah", "DHA 2", "11/10/2002");

    taskSystem.addTask(101, "Implement Feature A", 3, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 2, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003"); //complete
    taskSystem.addTask(104, "Write Test Cases", 1, "A004"); //2

    taskSystem.completeTask(103);
    taskSystem.updateTaskPriority(104, 2);

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.printTaskQueue(actualOutput);

    cout<<actualOutput.str();

    // Define the expected output
    std::string expectedOutput =
    "Task ID: 102, Description: Fix Bug in Module B, Priority: 2, Assignee: Amna (A002)\n"
    "Task ID: 104, Description: Write Test Cases, Priority: 2, Assignee: Ali (A004)\n"
    "Task ID: 101, Description: Implement Feature A, Priority: 3, Assignee: Aaimlik (A001)\n"
    ;

    // Compare the actual output with the expected output
    ASSERT_EQ(actualOutput.str(), expectedOutput);
}


//
//////////////Search task by priority range
TEST(SearchingY, priorityrange){
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Waqas", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Hur","Hashim", "Dha phase 4", "1/1/2002"); // A002 and so on.
    taskSystem.addAssignee("Hasan", "Khan", "I9", "2/11/2003");
    // Add tasks with various priority levels
    taskSystem.addTask(101, "Implement Feature A", 2, "A001");
    taskSystem.addTask(102, "Fix Bug in Module B", 3, "A002");
    taskSystem.addTask(103, "Write Unit Tests", 1, "A003");

    // Capture the actual output
    std::stringstream actualOutput;
    taskSystem.searchTasksByPriorityRange(1, 3, actualOutput);

    cout<<actualOutput.str()<<endl;
    // Define the expected output
    std::string expectedOutput = "Tasks within Priority Range (1 to 3):\n"
                                    "Task ID: 103, Description: Write Unit Tests, Priority: 1, Assignee: Hasan (A003)\n"
                                    "Task ID: 101, Description: Implement Feature A, Priority: 2, Assignee: Waqas (A001)\n"
                                    "Task ID: 102, Description: Fix Bug in Module B, Priority: 3, Assignee: Hur (A002)\n"
    ;

    // Compare the actual output with the expected output and display "PASS" or "FAIL"
    ASSERT_EQ(actualOutput.str(), expectedOutput);
}


//task tree printing
TEST(display_treeY, UpdateTaskPriorities) {
    taskManagementSystem taskSystem;

    taskSystem.addAssignee("Musa", "Khan", "I6", "2/12/2003");  //This should get A001
    taskSystem.addAssignee("Usaid","Hashim", "Dha phase 5", "1/2/2002"); // A002 and so on.
    taskSystem.addAssignee("Hussain", "Khan", "I5", "2/11/2003");
    taskSystem.addAssignee("Shahzaib","Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Qasim", "Khan", "I8", "2/12/2000");
    taskSystem.addAssignee("Amna","Hashim", "Dha phase 2", "1/2/2002");
    taskSystem.addAssignee("Zohaib", "Khan", "I6", "2/10/2002");
    taskSystem.addAssignee("Laila","Hashim", "Dha phase 2", "7/6/2002");
    // Add tasks
    taskSystem.addTask(101, "Task A", 7, "A001");
    taskSystem.addTask(102, "Task B", 6, "A002");
    taskSystem.addTask(103, "Task C", 3, "A003");
    taskSystem.addTask(104, "Task A", 5, "A004");
    taskSystem.addTask(105, "Task B", 4, "A005");
    taskSystem.addTask(106, "Task C", 1, "A006");
    taskSystem.addTask(107, "Task B", 8, "A007");
    taskSystem.addTask(108, "Task C", 9, "A008");

    // Display the initial tree
    std::stringstream initialTreeOutput;
    taskSystem.PrintTreeInorder(initialTreeOutput); //In Order Traversal with the color of that node
    taskSystem.updateTaskPriority(102, 2);
    // Display the updated tree
    std::stringstream updatedTreeOutput; //In Order Traversal with the color of that node
    taskSystem.PrintTreeInorder(updatedTreeOutput);

    // Define the expected output
    std::string expectedInitialTreeOutput =
    "106 (red)\n" //
    "103 (black)\n" //
    "105 (red)\n"
    "104 (black)\n"
    "102 (black)\n"
    "101 (red)\n"
    "107 (black)\n"
    "108 (red)\n";

    cout<<updatedTreeOutput.str()<<endl;

    std::string expectedUpdatedTreeOutput =
    "106 (black)\n"
    "102 (red)\n"
    "103 (red)\n"
    "105 (black)\n"
    "104 (black)\n"
    "101 (red)\n"
    "107 (black)\n"
    "108 (red)\n";

    // Check if the initial tree and updated tree match the expected output
    ASSERT_EQ(initialTreeOutput.str(), expectedInitialTreeOutput);
    ASSERT_EQ(updatedTreeOutput.str(), expectedUpdatedTreeOutput);
}










int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
