# Holiday-Management-OOP

This is the source code of the final project of Object Oriented Programming Training (2023 Summer), Tsinghua University. Create a demo for the holiday management function in a calendar application.

Model-View-Controller (MVC) files are saved in the same directory. `Festival.txt` contains festival information. `Controller.hpp/cpp` contain all classes and functions of controller. `main.cpp`  contains all interfaces and functions that is used for interaction. This project is developed, compiled and tested on local Windows 10, Visual Studio 2022 environment.

Basic functions:
- Adding, deleting, and modifying holidays. Holidays are divided into two types: one is a holiday with a given name, specific month, and date; the other is a holiday with a given name, specific month, and the occurrence of a specific day of the week (e.g., the last Sunday of May). Users can add, delete, or modify the specified holiday information.
- Automatic reading and saving of holiday information. When the software starts running, it automatically reads all holiday information saved in a specific text file. When the software exits, it automatically saves all holiday information to the specific text file.
- Calendar and holiday display. Given a specific year and month, the calendar and holidays for that month are displayed. The top of the interface shows a multi-row calendar with days of the week as columns, and the bottom displays the names of all holidays in the month and their specific dates.
- Holiday query and sorted display. Given a specific date range and sorting method (ascending by date or by holiday name), the list displays the holiday names along with the corresponding dates.
- Holiday countdown. Given a holiday name, the number of days remaining until that holiday from today is displayed.


