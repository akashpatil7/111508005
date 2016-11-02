Project: Logic Gate Simulator
Name: Akash Patil
MIS: 111508005
 
This application implements a Basic Logic Gate Simulator. 
The application consists of panel, grid and menu bar. The panel allows the user to select input and output controls and a range of logic gates (AND, OR, NOT, NAND, NOR, XOR, XNOR) to be displayed on a grid. On selecting a gate, another windows pops up which asks the user to select the number of inputs (2,3 or 4) for that particular gate and displays the gate with desired number of inputs on the grid. After the gate is displayed on the grid, the user can drag and drop the gate in the grid itself.
There are two modes of grid. On Selecting 'start' in option menu, the user cannot move any widget in the grid. On selecting 'stop', the user can move or drag and drop widgets in the grid.
To connect a switch/toggle to a gate, click on the end point on the input line where the terminal displays a message "Click the switch/toggle to be connected" and then click on the switch. The switch moves to those coordinates. Similar approach for output switches/toggles.
The 'New' option in the 'File' option in the Menu bar clears the grid to start with a new circuit and the 'Exit' option closes the application.

TO BE NOTED: The gates have created using the goocanvas library which allows us to create our own widgets with events.
     
NOTE: Do not move/resize the main window as the drag and drog of widgets is based on the coordinates of the widget with respect to the screen.
