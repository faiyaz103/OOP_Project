# DOC on the GO

This repository contains the source code for the "DOC on the GO" project. This project is made under the course Object Oriented Programming Laboratory (CSE 2102) associated with Khulna University of Engineering & Technology. It is a program that allows users to manage doctor appointments and doctor database information. The program provides functionality for both administrators and patients.

## Features

1. **Menu**: The program displays a menu with options to log in as an admin or use it as a patient.

2. **Admin Panel**: If logged in as an admin, the program provides options to visit the database, add a doctor to the database, modify the database, remove a doctor from the database, or go back to the main menu.

3. **Patient**: If used as a patient, the program provides options to make an appointment, go back to the main menu, or exit.

4. **Add Doctor to Database**: The admin can add a doctor to the database by providing details such as doctor's code, first name, last name, department, fees per visit, and visiting hour. The information is stored in a file named "docinfo.txt".

5. **Modify Database**: The admin can modify the database by editing the details of a doctor. The program lists the existing doctors and prompts the admin to enter the doctor code for the doctor they want to edit. The modified data is stored in the "docinfo.txt" file.

6. **Remove Doctor from Database**: The admin can remove a doctor from the database by entering the doctor code. The program removes the corresponding doctor's information from the "docinfo.txt" file.

7. **Doctor List**: The program displays a list of doctors with their codes, names, departments, fees, and visiting hours. It retrieves this information from the "docinfo.txt" file.

8. **Make Appointment**: The patient can make an appointment by selecting a doctor from the list and providing their personal details such as first name, last name, and phone number. The appointment information is stored in a file named "receipt.txt".

## Usage

To use this program, follow these steps:

1. Compile and run the program.
2. Select whether to use it as an admin or a patient.
3. If using it as an admin, log in with the provided email and password.
4. Depending on the role, select the appropriate options from the menu.
5. Follow the on-screen instructions to perform actions such as adding a doctor, modifying the database, or making an appointment.

## Contact

For any inquiries or issues, please contact the project maintainer at [faiyazmahmud2002@gmail.com](mailto:faiyazmahmud2002@gmail.com).
