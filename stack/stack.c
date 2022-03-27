typedef struct s_stack {
	int data;
	struct s_stack* next;
	struct s_stack* prev;
}	t_stack;

// stack_new -> create a new stack
// stack_len -> size of stack

// append -> add to end 
// pop -> remove from end 

// prepend -> add to beginning 
// shift -> remove from beginning 

// first -> get first element