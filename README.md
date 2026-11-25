# Voting Management System in C

A console-based **Voting Management System** developed in C language using basic file handling, structures, and array manipulations. This project simulates a simple electoral system where eligible voters can register, view candidate lists, cast their votes securely, and view election results along with turnout summaries.

---

## 🚀 Features

* **Voter Registration:** 
  * Validates voter age (must be 18 or older).
  * Automatically generates a unique Voter ID starting from `1000`.
  * Persists registered voter records into a local text file (`voters.txt`).
* **Candidate List:** 
  * Displays a pre-defined list of candidates running for the election.
* **Secure Voting System:** 
  * Authenticates voters using their unique Voter ID.
  * Prevents double-voting by tracking whether a voter has already cast their vote (`hasvoted` flag).
* **Winner Declaration & Tie Handling:** 
  * Automatically calculates vote counts and declares the winner.
  * Detects and handles election ties gracefully by listing all tied candidates.
* **Election Summary & Turnout Report:** 
  * Computes total registered voters, total votes cast, and overall voter turnout percentage.

---

## 🛠️ Technologies Used

* **Language:** C (Standard C99 / ANSI C)
* **Concepts Applied:**
  * Structures (`struct`)
  * File I/O (`fopen`, `fprintf`, `fclose`)
  * Control Statements & Loops (`do-while`, `switch-case`, `for`)
  * Arrays and Strings (`string.h`)

---

## 📂 Code Structure & Function Overview

| Function Name | Description |
| :--- | :--- |
| `main()` | Displays the main menu loop and handles user navigation options. |
| `registervoter()` | Captures voter details, checks age eligibility, assigns a unique ID, saves to `voters.txt`, and updates the runtime array. |
| `candidatelist()` | Prints the list of participating candidates with their respective ballot numbers. |
| `voting()` | Verifies the voter ID, checks if the user has already voted, and records their vote choice. |
| `winner()` | Computes maximum votes, checks for ties, and declares the election winner(s). |
| `showsummary()` | Calculates total votes cast and computes the overall voter turnout percentage. |

---

## ⚙️ How to Compile and Run

You can compile and run this program using any standard C compiler (like GCC on Linux/MinGW on Windows or Dev-C++ / Code::Blocks).

### Using GCC (Command Line)
1. Open your terminal or command prompt in the project directory.
2. Compile the source code:
   ```bash
   gcc voting_system.c -o voting_system
