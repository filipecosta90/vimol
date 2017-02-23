static const struct {
	const char *key;
	const char *command;
} keys[] = {
	{ "A", "add-hydrogens" },
	{ "S-A", "select-element H" },
	{ "B", "bond" },
	{ "C", "view-center-selection" },
	{ "S-C", "view-fit-selection" },
	{ "D", "delete" },
	{ "Delete", "delete" },
	{ "E", "unselect *" },
	{ "F", "view-zoom 1.15" },
	{ "G", "view-zoom 0.87" },
	{ "S-F", "view-rotate 0 0 -10" },
	{ "S-G", "view-rotate 0 0 10" },
	{ "H", "view-rotate 0 10 0" },
	{ "J", "view-rotate 10 0 0" },
	{ "K", "view-rotate -10 0 0" },
	{ "L", "view-rotate 0 -10 0" },
	{ "S-H", "view-move -0.1 0 0" },
	{ "S-J", "view-move 0 0.1 0" },
	{ "S-K", "view-move 0 -0.1 0" },
	{ "S-L", "view-move 0.1 0 0" },
	{ "I", "toggle id-visible" },
	{ "S-I", "toggle name-visible" },
	{ "M", "measure" },
	{ "N", "select-within" },
	{ "O", "toggle origin-visible" },
	{ "S-O", "move-selection-to" },
	{ "P", "paste" },
	{ "C-V", "paste" },
	{ "Q", "quit" },
	{ "S-Q", "quit!" },
	{ "R", "record" },
	{ "S", "select" },
	{ "T", "replay" },
	{ "U", "unselect" },
	{ "V", "hide-selection" },
	{ "W", "select-molecule" },
	{ "S-W", "select-water" },
	{ "X", "copy; delete" },
	{ "C-X", "copy; delete" },
	{ "Y", "copy" },
	{ "C-C", "copy" },
	{ "Z", "show-all" },
	{ "C-A", "select *" },
	{ "C-F", "rotate-selection 0 0 -10" },
	{ "C-G", "rotate-selection 0 0 10" },
	{ "C-H", "rotate-selection 0 10 0" },
	{ "C-J", "rotate-selection 10 0 0" },
	{ "C-K", "rotate-selection -10 0 0" },
	{ "C-L", "rotate-selection 0 -10 0" },
	{ "CS-H", "move-selection -0.1 0 0" },
	{ "CS-J", "move-selection 0 0.1 0" },
	{ "CS-K", "move-selection 0 -0.1 0" },
	{ "CS-L", "move-selection 0.1 0 0" },
	{ "C-R", "redo" },
	{ "C-Z", "undo" },
	{ "Left", "view-rotate 0 10 0" },
	{ "Down", "view-rotate 10 0 0" },
	{ "Up", "view-rotate -10 0 0" },
	{ "Right", "view-rotate 0 -10 0" },
	{ "S-Left", "view-move -0.1 0 0" },
	{ "S-Down", "view-move 0 0.1 0" },
	{ "S-Up", "view-move 0 -0.1 0" },
	{ "S-Right", "view-move 0.1 0 0" },
	{ "C-Left", "rotate-selection 0 10 0" },
	{ "C-Down", "rotate-selection 10 0 0" },
	{ "C-Up", "rotate-selection -10 0 0" },
	{ "C-Right", "rotate-selection 0 -10 0" },
	{ "CS-Left", "move-selection -0.1 0 0" },
	{ "CS-Down", "move-selection 0 0.1 0" },
	{ "CS-Up", "move-selection 0 -0.1 0" },
	{ "CS-Right", "move-selection 0.1 0 0" },
	{ "=", "invert-selection" },
	{ "Space", "fullscreen" },
	{ "`", "view-reset" },
	{ "[", "next-frame -1" },
	{ "]", "next-frame 1" },
	{ "S-[", "next-frame -100" },
	{ "S-]", "next-frame 100" },
	{ "S-,", "prev-tab" },
	{ "S-.", "next-tab" },
};
