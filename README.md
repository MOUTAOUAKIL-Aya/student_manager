Student Management System in C

This project is a console-based student management program written in C.
It allows users to add, modify, list, search, and delete student records while handling basic information like name, age, student ID, birth date, and subjects with grades.

Features :

-Add a new student with personal details, birth date, and subjects

-Modify an existing student’s information

-List all students with their details

-Search for a student by name

-Delete a student from the list

-Manage grades for subjects

-Dynamic memory allocation allows the program to handle an expanding list of students

Tech Stack :

-C programming language

-Standard libraries: <stdio.h>, <stdlib.h>, <string.h>, <conio.h>

-Data structures: struct for students, subjects, and dates

-Console-based application (no GUI)

-Dynamic arrays using malloc and realloc

The program displays a menu with 5 options:
  1. Add a student
  2. Modify a student
  3. List students
  4. Search a student
  5. Delete a student

Notes :

-Student names must be unique for searching and modification

-Dates must be valid (day: 1–31, month: 1–12)

-The program dynamically allocates memory for student records, so there is no fixed limit

Learning Goals :

-Practice C programming fundamentals: structures, pointers, arrays, and functions

-Learn dynamic memory management using malloc and realloc

-Build menu-driven console applications
