import java.util.*;

class Student {
    private String studentId; // Private field to store student ID
    private String name; // Private field to store student name
    private int age; // Private field to store student age
    private String major; // Private field to store student major
    private List<Module> enrolledModules; // Private list to store enrolled modules

    // Constructor to initialize a Student object with provided details
    public Student(String studentId, String name, int age, String major) {
        this.studentId = studentId;
        this.name = name;
        this.age = age;
        this.major = major;
        this.enrolledModules = new ArrayList<>(); // Initialize the list of enrolled modules
    }

    // Method to enroll a student in a module
    public void enrollModule(Module module) {
        enrolledModules.add(module);
    }

    // Method to unenroll a student from a module
    public void unenrollModule(Module module) {
        enrolledModules.remove(module);
    }

    // Method to retrieve the list of enrolled modules
    public List<Module> getEnrolledModules() {
        return enrolledModules;
    }

    // Override toString method to provide a string representation of the Student object
    @Override
    public String toString() {
        return "Student{" +
                "studentId='" + studentId + '\'' +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", major='" + major + '\'' +
                '}';
    }

    // Getters and setters for private fields
    public String getStudentId() {
        return studentId;
    }

    public void setStudentId(String studentId) {
        this.studentId = studentId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }
}

class Module {
    private String courseId; // Private field to store module ID
    private String courseName; // Private field to store module name
    private String instructor; // Private field to store module instructor
    private int capacity; // Private field to store module capacity
    private List<Student> enrolledStudents; // Private list to store enrolled students

    // Constructor to initialize a Module object with provided details
    public Module(String courseId, String courseName, String instructor, int capacity) {
        this.courseId = courseId;
        this.courseName = courseName;
        this.instructor = instructor;
        this.capacity = capacity;
        this.enrolledStudents = new ArrayList<>(); // Initialize the list of enrolled students
    }

    // Override toString method to provide a string representation of the Module object
    @Override
    public String toString() {
        return "Module{" +
                "courseId='" + courseId + '\'' +
                ", courseName='" + courseName + '\'' +
                ", instructor='" + instructor + '\'' +
                ", capacity=" + capacity +
                ", enrolledStudents=" + enrolledStudents +
                '}';
    }

    // Getters and setters for private fields
    public String getCourseId() {
        return courseId;
    }

    public void setCourseId(String courseId) {
        this.courseId = courseId;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public String getInstructor() {
        return instructor;
    }

    public void setInstructor(String instructor) {
        this.instructor = instructor;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public List<Student> getEnrolledStudents() {
        return enrolledStudents;
    }

    // Method to register a student to the module
    public void registerStudent(Student student) {
        if (enrolledStudents.size() < capacity) { // Check if module has available capacity
            enrolledStudents.add(student); // Add student to enrolled list
            student.enrollModule(this); // Enroll module in student
            System.out.println(student.getName() + " has been successfully registered to " + courseName + "!");
        } else {
            System.out.println("Sorry, " + student.getName() + "! The module is already full.");
        }
    }

    // Method to deregister a student from the module
    public void deregisterStudent(Student student) {
        if (enrolledStudents.remove(student)) { // Check if student is enrolled and remove
            student.unenrollModule(this); // Unenroll module from student
            System.out.println(student.getName() + " has been successfully deregistered from " + courseName + ".");
        } else {
            System.out.println(student.getName() + " is not enrolled in " + courseName + ".");
        }
    }
}

class RegistrationSystem {
    private Map<String, Student> students; // Private map to store students by ID
    private Map<String, Module> modules; // Private map to store modules by ID
    private PriorityQueue<Module> moduleQueue; // Private priority queue to manage module enrollment status

    // Constructor to initialize the RegistrationSystem
    public RegistrationSystem() {
        students = new HashMap<>(); // Initialize students map
        modules = new HashMap<>(); // Initialize modules map
        moduleQueue = new PriorityQueue<>(Comparator.comparingInt(m -> -m.getEnrolledStudents().size())); // Initialize priority queue sorted by enrolled student count
    }

    // Method to add a student to the system
    public void addStudent(Student student) {
        students.put(student.getStudentId(), student); // Add student to students map
        System.out.println("Welcome, " + student.getName() + "! You've been added as a student.");
    }

    // Method to add a module to the system
    public void addModule(Module module) {
        modules.put(module.getCourseId(), module); // Add module to modules map
        moduleQueue.offer(module); // Add module to priority queue
    }

    // Method to remove a module from the system
    public void removeModule(String courseId) {
        Module module = modules.remove(courseId); // Remove module from modules map
        if (module != null) {
            moduleQueue.remove(module); // Remove module from priority queue
            System.out.println("Module " + module.getCourseName() + " has been removed.");
        } else {
            System.out.println("Module not found!");
        }
    }

    // Method to update details of a module in the system
    public void updateModuleDetails(String courseId, String newCourseName, String newInstructor, int newCapacity) {
        Module module = modules.get(courseId); // Retrieve module from modules map
        if (module != null) {
            module.setCourseName(newCourseName); // Update module details
            module.setInstructor(newInstructor);
            module.setCapacity(newCapacity);
            moduleQueue.remove(module); // Update module in priority queue
            moduleQueue.offer(module);
            System.out.println("Module " + courseId + " has been updated!");
        } else {
            System.out.println("Module not found!");
        }
    }

    // Method to register a student to a module
    public void registerStudentToModule(String studentId, String courseId, String Major) {
        Student student = students.get(studentId); // Retrieve student from students map
        Module module = modules.get(courseId); // Retrieve module from modules map
        if (student != null && module != null) {
            module.registerStudent(student); // Register student to module
            moduleQueue.remove(module); // Update module in priority queue
            moduleQueue.offer(module);
        } else {
            System.out.println("Invalid student ID or module ID.");
        }
    }

    // Method to deregister a student from a module
    public void deregisterStudentFromModule(String studentId, String courseId) {
        Student student = students.get(studentId); // Retrieve student from students map
        Module module = modules.get(courseId); // Retrieve module from modules map
        if (student != null && module != null) {
            module.deregisterStudent(student); // Deregister student from module
            moduleQueue.remove(module); // Update module in priority queue
            moduleQueue.offer(module);
        } else {
            System.out.println("Invalid student ID or module ID.");
        }
    }

    // Method to display details of a student
    public void showStudentDetails(String studentId) {
        Student student = students.get(studentId); // Retrieve student from students map
        if (student != null) {
            System.out.println("Here are the details for " + student.getName() + ": " + student);
        } else {
            System.out.println("Oops! Student not found.");
        }
    }

    // Method to display modules enrolled by a student
    public void showStudentModules(String studentId) {
        Student student = students.get(studentId); // Retrieve student from students map
        if (student != null) {
            List<Module> modules = student.getEnrolledModules(); // Retrieve modules enrolled by student
            if (modules.isEmpty()) {
                System.out.println(student.getName() + " is not enrolled in any modules.");
            } else {
                System.out.println("Modules " + student.getName() + " is currently enrolled in:");
                for (Module module : modules) {
                    System.out.println(module.getCourseId() + " - " + module.getCourseName() + " (" + module.getInstructor() + ")");
                }
            }
        } else {
            System.out.println("Oops! Student not found.");
        }
    }

    // Method to display details of a module
    public void showModuleDetails(String courseId) {
        Module module = modules.get(courseId); // Retrieve module from modules map
        if (module != null) {
            System.out.println("Here's the scoop on " + module.getCourseName() + ": " + module);
        } else {
            System.out.println("Oops! Module not found.");
        }
    }

    // Method to display enrollment status of all modules
    public void showEnrollmentStatus() {
        System.out.println("Here's the current enrollment status:");
        for (Module module : moduleQueue) {
            System.out.println(module.getCourseName() + " - Enrolled Students: " + module.getEnrolledStudents().size());
        }
    }
}

// Main class to simulate user interface for student registration system
public class userInterface {
    public static void main(String[] args) {
        RegistrationSystem registrationSystem = new RegistrationSystem(); // Create a new registration system instance

        // Creating variables for user input:
        Scanner scanner = new Scanner(System.in); // Scanner object to read user input
        String sID; // Variable to store student ID
        String sName; // Variable to store student name
        int sAge; // Variable to store student age
        String sMajor; // Variable to store student major

        // Creating modules for different classes:
        // Mechanical Engineering:
        Module m1 = new Module("M001", "Engineering 101", "Dr. Martinez", 2);
        Module m2 = new Module("M002", "Mechanics", "Dr. Anaya", 2);
        // Computer Science:
        Module m3 = new Module("M003", "Data Structures", "Dr. Smith", 2);
        Module m4 = new Module("M004", "Computer Architecture", "Dr. Snellville", 2);
        // Chemistry:
        Module m5 = new Module("M005", "General Chemistry", "Dr. Watanabe", 2);
        Module m6 = new Module("M006", "Organic Chemistry", "Dr. Lane", 2);
        // Nursing:
        Module m7 = new Module("M007", "Principles of Health Science", "Dr. Stonem", 2);
        Module m8 = new Module("M008", "Nursing", "Dr. Reynolds", 2);

        registrationSystem.addModule(m1); // Add module m1 to registration system
        registrationSystem.addModule(m2); // Add module m2 to registration system
        registrationSystem.addModule(m3); // Add module m3 to registration system
        registrationSystem.addModule(m4); // Add module m4 to registration system
        registrationSystem.addModule(m5); // Add module m5 to registration system
        registrationSystem.addModule(m6); // Add module m6 to registration system
        registrationSystem.addModule(m7); // Add module m7 to registration system
        registrationSystem.addModule(m8); // Add module m8 to registration system

        // Prompting user for input:
        System.out.println(" 𖨆 < Hello, welcome to Lone Star Kingwood! I'm your admissions counselor.");

        System.out.println(" 𖨆 < Can you tell me your student id?");
        sID = scanner.nextLine(); // Read student ID from user input

        System.out.println(" 𖨆 < Can you tell me your first and last name?");
        sName = scanner.nextLine(); // Read student name from user input

        System.out.println(" 𖨆 < Can you tell me your major (enter as the full string)?");
        System.out.println("MAJORS OFFERED AT LONE STAR KINGWOOD:");
        System.out.println("Computer Science");
        System.out.println("Nursing");
        System.out.println("Chemistry");
        System.out.println("Mechanical Engineering");
        sMajor = scanner.nextLine(); // Read student major from user input

        System.out.println(" 𖨆 < Can you tell me your age?");
        sAge = scanner.nextInt(); // Read student age from user input

        System.out.println(" 𖨆 < Perfect! You're now registered in our student database. How can I help you today?");

        // Adding first student entry:
        Student s1 = new Student(sID, sName, sAge, sMajor); // Create new student object
        registrationSystem.addStudent(s1); // Add student s1 to registration system

        // CLI Simulation loop:
        while (true) {
            System.out.println("1. Register for a Module");
            System.out.println("2. Deregister from a Module");
            System.out.println("3. View Student Details");
            System.out.println("4. View Module Details");
            System.out.println("5. View Enrollment Status");
            System.out.println("6. Add a New Module");
            System.out.println("7. Remove a Module");
            System.out.println("8. Update Module Details");
            System.out.println("9. Register a new student");
            System.out.println("10. Exit");

            int choice = scanner.nextInt(); // Read user choice from input
            scanner.nextLine();  // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter Student ID: ");
                    String studentId = scanner.nextLine(); // Read student ID from user

                    System.out.print("Enter Student Major: ");
                    String sMaj = scanner.nextLine(); // Read student major from user

                    System.out.println("Modules available to you are: ");
                    // Display modules based on student major
                    if (sMaj.length() >= 20) { // Mechanical Engineering
                        System.out.println("Module #M001, Class Name: Engineering 101, Instructor: Dr. Martinez");
                        System.out.println("Module #M002, Class Name: Mechanics, Instructor: Dr. Anaya");
                    } else if (sMaj.length() < 20 && sMaj.length() > 14) { // Computer Science
                        System.out.println("Module #M003, Class Name: Data Structures, Instructor: Dr. Smith");
                        System.out.println("Module #M004, Class Name: Computer Architecture, Instructor: Dr. Snellville");
                    } else if (sMaj.length() < 14 && sMaj.length() > 7) { // Chemistry
                        System.out.println("Module #M005, Class Name: Organic Chemistry, Instructor: Dr. Watanabe");
                        System.out.println("Module #M006, Class Name: General Chemistry, Instructor: Dr. Lane");
                    } else if (sMaj.length() <= 7) { // Nursing
                        System.out.println("Module #M007, Class Name: Principles of Health Science, Instructor: Dr. Stonem");
                        System.out.println("Module #M008, Class Name: Nursing, Instructor: Dr. Reynolds");
                    }

                    System.out.print("Enter Module ID of desired course: ");
                    String courseId = scanner.nextLine(); // Read module ID from user
                    registrationSystem.registerStudentToModule(studentId, courseId, sMajor); // Register student to module
                    break;
                case 2:
                    System.out.print("Enter Student ID: ");
                    studentId = scanner.nextLine(); // Read student ID from user

                    // Display enrolled modules for the student
                    registrationSystem.showStudentModules(studentId);

                    System.out.print("Enter Module ID of course you wish to unenroll in: ");
                    courseId = scanner.nextLine(); // Read module ID from user
                    registrationSystem.deregisterStudentFromModule(studentId, courseId); // Deregister student from module
                    break;
                case 3:
                    System.out.print("Enter Student ID: ");
                    studentId = scanner.nextLine(); // Read student ID from user
                    registrationSystem.showStudentDetails(studentId); // Display student details
                    break;
                case 4:
                    System.out.print("Enter Module ID: ");
                    courseId = scanner.nextLine(); // Read module ID from user
                    registrationSystem.showModuleDetails(courseId); // Display module details
                    break;
                case 5:
                    registrationSystem.showEnrollmentStatus(); // Display enrollment status of all modules
                    break;
                case 6:
                    System.out.print("Enter Module ID: ");
                    courseId = scanner.nextLine(); // Read module ID from user
                    System.out.print("Enter Module Name: ");
                    String courseName = scanner.nextLine(); // Read module name from user
                    System.out.print("Enter Instructor: ");
                    String instructor = scanner.nextLine(); // Read instructor name from user
                    System.out.print("Enter Capacity: ");
                    int capacity = scanner.nextInt(); // Read module capacity from user
                    scanner.nextLine();  // Consume newline
                    Module newModule = new Module(courseId, courseName, instructor, capacity); // Create new module object
                    registrationSystem.addModule(newModule); // Add new module to registration system
                    break;
                case 7:
                    System.out.print("Enter Module ID: ");
                    courseId = scanner.nextLine(); // Read module ID from user
                    registrationSystem.removeModule(courseId); // Remove module from registration system
                    break;
                case 8:
                    System.out.print("Enter Module ID: ");
                    courseId = scanner.nextLine(); // Read module ID from user
                    System.out.print("Enter New Module Name: ");
                    String newCourseName = scanner.nextLine(); // Read new module name from user
                    System.out.print("Enter New Instructor: ");
                    String newInstructor = scanner.nextLine(); // Read new instructor name from user
                    System.out.print("Enter New Capacity: ");
                    int newCapacity = scanner.nextInt(); // Read new module capacity from user
                    scanner.nextLine();  // Consume newline
                    registrationSystem.updateModuleDetails(courseId, newCourseName, newInstructor, newCapacity); // Update module details
                    break;
                case 9:
                    // Creating variables for user input:
                    String ssID;
                    String ssName;
                    int ssAge;
                    String ssMajor;

                    System.out.println(" 𖨆 < Hello, new student! Can you tell me your student id?");
                    ssID = scanner.nextLine(); // Read student ID from user

                    System.out.println(" 𖨆 < Can you tell me your first and last name?");
                    ssName = scanner.nextLine(); // Read student name from user

                    System.out.println(" 𖨆 < Can you tell me your major (enter as the full string)?");
                    ssMajor = scanner.nextLine(); // Read student major from user

                    System.out.println(" 𖨆 < Can you tell me your age?");
                    ssAge = scanner.nextInt(); // Read student age from user

                    Student nStudent = new Student(ssID, ssName, ssAge, ssMajor); // Create new student object
                    registrationSystem.addStudent(nStudent); // Add new student to registration system
                    break;
                case 10:
                    System.out.println("Thank you for using the Student Registration Management System. Goodbye!");
                    scanner.close(); // Close scanner
                    return; // Exit program
                default:
                    System.out.println("Invalid choice. Please try again."); // Display error message for invalid choice
            }
        }
    }
}
