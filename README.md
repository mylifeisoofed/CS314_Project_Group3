# ChocAn Data Processing Software

Welcome to the ChocAn Data Processing Software repository! This software serves as a medical terminal for ChocAn Medical Services, allowing providers to check in ChocAn members and perform various administrative tasks.

## Features

- **Member Check-in:** Providers can use the terminal to check in ChocAn members efficiently.
- **Provider Lookup:** Quickly search and view information about providers in the database.
- **Appointment Management:** Create and manage appointments for members and providers.
- **Report Summaries:** Generate summaries of appointments and reports as text files.
- **Database Management:** Add and remove members and providers from the database.

## Development

The software is programmed entirely in C++. The software uses a custom-implemented template hash table to efficiently store and retrieve data about all members and providers in the database.  

This software was developed as a group project for **CS314: Elements of Software Engineering** at Portland State University Winter Term 2024.

## Contributors

This software was primarily developed by the following individuals:

- **mylifeisoofed (Brian Le/Me)** - Developer
    - Email: [bpl4@pdx.edu](mailto:bpl4@pdx.edu)
- **Tommy Camou** - Developer
    - Email: [tcamou@pdx.edu](mailto:tcamou@pdx.edu)

## Getting Started

To get started with the software:

1. Clone this repository:

    ```shell
    git clone https://github.com/your-username/ChocAn-Data-Processing-Software.git
    ```

2. Navigate to the project directory:

    ```shell
    cd ChocAn-Data-Processing-Software
    ```

3. Compile and run the program!

## Usage

There are two terminals provided by the software:

- **Provider Terminal**: This terminal is for ChocAn providers to check in members and assign them to specific caregivers and providers. 
- **Manager Terminal**: This terminal allows users to manage the ChocAn database by adding or removing members or providers. Accessing the Manager Terminal requires administrator credentials.

### Administrator Credentials
- The administrator credentials can be found in the file `admin_cred.txt`.
- You can change the administrator credentials by editing the `admin_cred.txt` file.

