/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Prototype
 */

#include "prototype.hpp"

#include <iomanip>
#include <iostream>
#include <string>

void trim_ws_beg(std::string &command)
{
    size_t non_ws = command.find_first_not_of(WHITESPACE);
    if (non_ws != std::string::npos)
    {
        command.erase(0, non_ws);
    }
}

void trim_ws_end(std::string &command)
{
    size_t non_ws = command.find_last_not_of(WHITESPACE);
    if (non_ws != std::string::npos)
    {
        command.erase(non_ws + 1);
    }
}

void trim_ws(std::string &command)
{
    trim_ws_beg(command);
    trim_ws_end(command);
}

bool all_whitespace(std::string &command)
{
    bool is_all_whitespace = true;
    // check all characters in command for whitespace
    for (char c : command)
    {
        if (!std::isspace(c))
        {
            is_all_whitespace = false;
            break;
        }
    }

    // treat command as an empty response
    if (is_all_whitespace)
    {
        command.erase(0, command.length());
    }
    return is_all_whitespace;
}

bool obtain_command(std::string &command)
{
    bool command_valid = false;
    bool is_all_whitespace = false;
    std::getline(std::cin, command);
    trim_ws(command);
    is_all_whitespace = all_whitespace(command);

    // command valid if it has no whitespace or is all whitespace
    if ((command.find(WHITESPACE) == std::string::npos) || is_all_whitespace)
    {
        command_valid = true;
    }
    return command_valid;
}

void run_delete(void)
{
    std::cout << "\nInput String Number: 1\n"
              << "Input string aabb successfully deleted from list!\n"
              << std::endl;
}

void run_exit(void)
{
    std::cout << "\nInput strings list successfully written to file!" << std::endl;
}

void run_help(void)
{
    // space between the command and description
    int outw = 11;
    std::cout << "\n"
              << UL << "Command" << RM_UL << std::setw(outw - 7) << std::left << "" << UL << "Description\n"
              << RM_UL << UL << "D" << RM_UL << std::setw(outw - 1) << std::left << "elete"
              << "Delete input string from list\n"
              << "E" << UL << "x" << RM_UL << std::setw(outw - 2) << std::left << "it" << "Exit application\n"
              << UL << "H" << RM_UL << std::setw(outw - 1) << std::left << "elp" << "Help user\n"
              << UL << "I" << RM_UL << std::setw(outw - 1) << std::left << "nsert" << "Insert input string into list\n"
              << UL << "L" << RM_UL << std::setw(outw - 1) << std::left << "ist" << "List input strings\n"
              << UL << "Q" << RM_UL << std::setw(outw - 1) << std::left << "uit"
              << "Quit operation of Turing machine on input string\n"
              << UL << "R" << RM_UL << std::setw(outw - 1) << std::left << "un"
              << "Run Turing machine on input string\n"
              << "S" << UL << "e" << RM_UL << std::setw(outw - 2) << std::left << "t"
              << "Set maximum number of transitions to perform\n"
              << "Sho" << UL << "w" << RM_UL << std::setw(outw - 4) << std::left << "" << "Show status of application\n"
              << UL << "T" << RM_UL << std::setw(outw - 1) << std::left << "runcate"
              << "Truncate instantaneous descriptions\n"
              << UL << "V" << RM_UL << std::setw(outw - 1) << std::left << "iew" << "View Turing machine\n"
              << std::endl;
}

void run_insert(void)
{
    std::cout << "\nInput String: aabb\n"
              << "Input string aabb successfully entered into list!\n"
              << std::endl;
}

void run_list(void)
{
    std::cout << "\n1. aa\n"
              << "2. aabb\n"
              << "3. \\\n"
              << "4. abab\n"
              << std::endl;
}

void run_quit(void)
{
    std::cout << "\nInput string abab is not accepted or rejected in 20 transitions.\n" << std::endl;
}

void run_run(void)
{
    std::cout << "\nInput String Number: 2\n"
              << "0.[s0]aabb\n"
              << "20.XY[s4]XY\n"
              << "Input string aabb is accepted in 20 transitions.\n"
              << std::endl;
}

void run_set(void)
{
    std::cout << "\nMaximum Number of Transitions [1]: 2\n"
              << "Value successfully changed to 2!\n"
              << std::endl;
}

void run_show(void)
{
    std::cout << "\nCourse: CPT_S 322\n"
              << "Semester: Spring\n"
              << "Year: 2025\n"
              << "Instructor: Neil Corrigan\n"
              << "Author: Alex Carbajal\n"
              << "Version: 0.0\n"
              << "Maximum Number of Transitions: 1\n"
              << "Maximum Instantaneous Description Cells: 32\n"
              << "Turing Machine Name: anbn\n"
              << "Turing Machine Status: Has not been run during session\n"
              << "Input Strings List Status: Modified\n"
              << std::endl;
}

void run_truncate(void)
{
    std::cout << "\nMaximum Instantaneous Description Cells [32]: 2\n"
              << "Value successfully changed to 2!\n"
              << std::endl;
}

void run_view(void)
{
    std::cout << "\nThis Turing machine accepts the language of one or more A's followed by the same number of B's.\n\n"
              << "Q = {s0, s1, s2, s3, s4}\n\n"
              << "Σ = {a, b}\n\n"
              << "Γ = {a, b, X, Y, -}\n\n"
              << "δ(s0, a) = (s1, X, R)\n"
              << "δ(s0, Y) = (s3, Y, R)\n"
              << "δ(s1, a) = (s1, a, R)\n"
              << "δ(s1, b) = (s2, Y, L)\n"
              << "δ(s1, Y) = (s1, Y, R)\n"
              << "δ(s2, a) = (s2, a, L)\n"
              << "δ(s2, X) = (s0, X, R)\n"
              << "δ(s2, Y) = (s2, Y, L)\n"
              << "δ(s3, Y) = (s3, Y, R)\n"
              << "δ(s3, -) = (s4, -, R)\n\n"
              << "q0 = s0\n\n"
              << "B = -\n\n"
              << "F = {s4}\n"
              << std::endl;
}

void run_invalid_command(void)
{
    std::cout << "\nInvalid command. Enter 'h' for help.\n" << std::endl;
}
