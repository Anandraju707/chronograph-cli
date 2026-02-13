📝 ChronoGraph CLI (C++)
A backend-first text editing engine that supports non-linear undo/redo using a tree-based history model, allowing branching timelines instead of a single linear edit history.
This project focuses on core computer science concepts such as data structures, memory ownership, immutability, and system design, independent of any graphical interface.

🚀 Motivation
While conventional text engines use linear memory and has the ability to undo/redo, 
it lacks the ability to retrace old branches. This prompted me to develop an engine that could store all mutations/edits and not lose old drafts or ideas the user may have.
While text engines are not a new concept, this project explores an alternative history model that preserves branching ideas rather than discarding them.

🧠 Core Concepts
Tree-based history model (not stack-based)
Immutable text snapshots
Explicit ownership using std::unique_ptr
Parent–child traversal for undo/redo
Backend-first design (UI-agnostic)

🏗 Architecture Overview
TextState - 
Immutable value object
Represents a snapshot of the document at a given point in time
Stored in each history node
HistoryGraph - 
Owns and manages all TextState objects
Maintains a tree of edit history
Tracks:
Current position
Active branch
Most recent “front” state

History Model
<ROOT>
 └── First
     └── Second
         ├── Third
         │   └── Fourth
         └── Branch
Undo moves up the tree
Redo moves down the active branch
⚙️ Features (v0)
Add new text states
Undo and redo across branches
Preserve alternate edit paths
Jump directly to root or front
Inspect full edit history path
Command-line interface (CLI) for interaction

💻 CLI Commands
Command	Description
add <text>	Add a new text state
undo	Move to parent state
redo	Move forward along active branch
current	Show current text
history	Print active history path
root	Jump to root state
front	Jump to most recent state
exit	Quit the program
🛠 Build & Run

Requirements
C++17 or newer
CMake
macOS / Linux (tested on macOS)
 - Build - 
mkdir build
cd build
cmake ..
cmake --build .
- Run -
./Text_editor_App

📂 Project Structure
Text_editor_App/
├── src/
│   ├── main.cpp
│   ├── HistoryGraph.hpp / .cpp
│   ├── TextState.hpp / .cpp
├── build/
├── CMakeLists.txt
├── README.md

🧪 Example Usage
> add First
> add Second
> add Third
> undo
> add Branch
> history
<ROOT>
First
Second
Branch

📈 Future Improvements and Implementations
Full tree visualization (printTree)
Branch switching commands
    - This would give full traversal capabilities and directly solve the
    initial problem which prompted me to design and develop this engine
Text mutation instead of full snapshot replacement
GUI frontend (Qt / web / terminal UI)
Interactive Text Writing Application
    - An extension and implementation that would allow users to work on their own projects without losing older drafts.
Songwriting assistant built on this engine
    - A much bigger yet feasible product which would enable artists to efficiently create without losing ideas.
Persistent save/load support

👤 Author
Anand Raju
Computer Science & Audio Production
Middle Tennessee State University

🧠 Final Notes
This project is intentionally backend-focused.
The CLI is a debugging and inspection tool — not the final interface.


