pragma solidity ^0.8.0;

contract StudentData {
    // Structure to represent student information
    struct Student {
        string name;
        uint256 rollNumber;
        uint256 age;
    }

    // Array to store a list of students
    Student[] public students;

    // Function to add a new student
    function addStudent(string memory _name, uint256 _rollNumber, uint256 _age) public {
        Student memory newStudent = Student(_name, _rollNumber, _age);
        students.push(newStudent);
    }

    // Function to retrieve student information by index
    function getStudent(uint256 index) public view returns (string memory, uint256, uint256) {
        require(index < students.length, "Student does not exist");
        Student storage student = students[index];
        return (student.name, student.rollNumber, student.age);
    }

    // Fallback function
    receive() external payable {
        // Fallback function can be used for receiving ether
        // You can add custom logic here if needed
    }
}