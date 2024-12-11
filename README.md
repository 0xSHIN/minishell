# Minishell

## Overview

Minishell is a simple implementation of a UNIX shell, designed to replicate basic shell functionality and reinforce concepts of system programming.

## Features

- Command parsing and execution.
- Built-in commands: cd, pwd, echo, exit.
- Environment variable support ($VARIABLE).
- Input/output redirection (<, >, >>) and piping (|).
- Graceful signal handling (Ctrl+C, Ctrl+D).
- Error handling with descriptive messages.

## Requirements

- UNIX-like operating system (Linux, macOS, etc.).
- C compiler (e.g., gcc).

## Installation

1. Clone the repository
2. Compile the project using Make
3. Run the shell

## Usage

- Launch the shell by running `./minishell`.
- Enter commands as you would in a standard shell.
- Use `exit` to quit the shell.

### Example Commands

- $ pwd
- $ cd ..
- $ echo "Welcome to Minishell" Welcome to Minishell
- $ ls -l | grep minishell > output.txt
- $ cat output.txt



