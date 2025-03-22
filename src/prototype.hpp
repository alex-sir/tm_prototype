/**
 *  Alex Carbajal
 *  CPT_S 322, Spring 2025
 *  Turing Machine Prototype
 */

#pragma once

#include <string>

// all whitespace characters as defined in std::isspace
#define WHITESPACE " \f\n\r\t\v"
// underline ANSI escape codes
#define UL "\033[4m"
#define RM_UL "\033[24m"

/**
 * @brief trim leading whitespace from the beginning of the command string
 *
 * @param command string to remove whitespace from
 */
void trim_ws_beg(std::string &command);
/**
 * @brief trim trailing whitespace from the end of the command string
 *
 * @param command string to remove whitespace from
 */
void trim_ws_end(std::string &command);
/**
 * @brief trim leading & trailing whitespace from the command string
 *
 * @param command string to remove whitespace from
 */
void trim_ws(std::string &command);
/**
 * @brief check if the command string contains only whitespace
 *
 * @param command string to check for only whitespace
 * @return true if the command string contains only whitespace
 *         false if it contains non-whitespace characters
 */
bool all_whitespace(std::string &command);

/**
 * @brief obtain a command from the user and check its validity
 *
 * @param command string to contain the command
 * @return true if the command is valid
 *         false if the command is invalid
 */
bool obtain_command(std::string &command);

/**
 * @brief run the delete command 'd'
 *        user selects a string to delete from the list
 */
void run_delete(void);
/**
 * @brief run the exit command 'x'
 *        user exits the application
 */
void run_exit(void);
/**
 * @brief run the help command 'h'
 *        display commands and their descriptions
 */
void run_help(void);
/**
 * @brief run the insert command 'i'
 *        user inputs a string to insert into the list
 */
void run_insert(void);
/**
 * @brief run the list command 'l'
 *        display input strings list
 */
void run_list(void);
/**
 * @brief run the quit command 'q'
 *        stop Turing machine operation on the input string
 */
void run_quit(void);
/**
 * @brief run the run command 'r'
 *        user inputs a string to run the Turing machine on
 *        or continues operation on an existing input string
 */
void run_run(void);
/**
 * @brief run the set command 'e'
 *        user sets the maximum number of transitions to perform
 */
void run_set(void);
/**
 * @brief run the show command 'w'
 *        display status of the application
 */
void run_show(void);
/**
 * @brief run the truncate command 't'
 *        user sets the maximum number of cells for the instantaneous descriptions
 */
void run_truncate(void);
/**
 * @brief run the view command 'v'
 *        display Turing machine description
 */
void run_view(void);
/**
 * @brief display a message after user inputs an invalid command
 */
void run_invalid_command(void);
