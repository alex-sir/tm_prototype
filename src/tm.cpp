/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Prototype
 */

#include "prototype.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::cout << "anbn successfully loaded!\n" << std::endl;

    std::string command = "";
    bool command_valid = false;
    bool exit = false;
    while (!exit)
    {
        std::cout << "Command: ";
        command_valid = obtain_command(command);
        if (command_valid && command.length() <= 1)
        {
            switch (std::tolower(command[0]))
            {
            case 'd': // Delete
                run_delete();
                break;
            case 'x': // Exit
                run_exit();
                exit = true;
                break;
            case 'h': // Help
                run_help();
                break;
            case 'i': // Insert
                run_insert();
                break;
            case 'l': // List
                run_list();
                break;
            case 'q': // Quit
                run_quit();
                break;
            case 'r': // Run
                run_run();
                break;
            case 'e': // Set
                run_set();
                break;
            case 'w': // Show
                run_show();
                break;
            case 't': // Truncate
                run_truncate();
                break;
            case 'v': // View
                run_view();
                break;
            case '\0': // empty response is ignored
                break;
            default: // command does not exist
                run_invalid_command();
                break;
            }
        }
        else
        {
            run_invalid_command();
        }
    }

    std::exit(EXIT_SUCCESS);
}
