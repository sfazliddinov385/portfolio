# Portfolio
# Corner Grocer Item-Tracking Program  
_CS 210 • Module Eight Portfolio Artifact_

---

## Project Summary  
I built a C++ console application that reads a plain-text sales log, tallies every grocery item sold, and outputs the results in three formats:  
1. A list of each unique item with its frequency  
2. The frequency for a single user-queried item  
3. A simple text-based histogram for all items  

This solves the store’s problem of **manually** counting daily sales, giving staff an instant, reproducible report they can run at close of business.

---

## Reflection

### What did I do particularly well?  
I’m proud of how clean and modular the code turned out. I separated file I/O, data aggregation, and UI logic into distinct functions, which keeps `main()` short and readable.

### Where could I enhance my code?  
*   **Efficiency:** Reading the file line-by-line works for small logs, but using a buffered stream or memory-mapped file would scale better if the store grows.  
*   **Security:** Adding simple validation for user input (e.g., rejecting empty strings) would harden the histogram query.  
*   **Portability:** Wrapping file paths with `std::filesystem` would make the code more OS-agnostic.

### Most challenging pieces and how I overcame them  
Parsing mixed-case item names without double-counting took the most time. I solved it by normalizing every line to lowercase with `<algorithm>` and `<cctype>`. When I got stuck, I leaned on [cppreference.com](https://en.cppreference.com) and the VS debugger’s watch window.

### Transferable skills  
*   **Modular design** translates to any language.  
*   **Version control discipline:** multiple, descriptive Git commits.  
*   **Data structures:** choosing an `unordered_map` for O(1) lookups is directly applicable to future data-engineering work.

### Making the code maintainable, readable, and adaptable  
*   Consistent naming (`camelCase` for functions, `UPPER_SNAKE` for constants).  
*   Doxygen-style comments above every public function.  
*   Single-responsibility functions and no “magic numbers” (all constants pulled into `constants.h`).  
*   Clear separation between logic and presentation—if the store ever wants a GUI, I can swap the console UI layer without touching the aggregation engine.

---

## How to Run

```bash
g++ -std=c++17 -o ItemTracker main.cpp
./ItemTracker

