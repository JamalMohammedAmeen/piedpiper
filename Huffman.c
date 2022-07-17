void generate_huffman_tree(node *n, char *code){
if(n->left== NULL && n->right== NULL){
    SYMBOLS[code_counter] = n->symbol; // this 3 lines just store current code, not important
    CODES[code_counter] = strdup(code);
    code_counter += 1;
}
if(n->left!= NULL){
    char temp[100];
    strcpy(temp, code);
    strcat(temp, "0");
    generate_huffman_tree(n->left, temp);
}
if(n->right!= NULL){
    char temp[100];
    strcpy(temp, code);
    strcat(temp, "1");
    generate_huffman_tree(n->right, temp);
}
node *build_huffman_tree(double *probabilities){

int num_of_nodes = NUM_SYMBOLS;
int num = NUM_SYMBOLS;

// 1) Initialization: Create new node for every probability
node *leafs = (node*) malloc(num_of_nodes*sizeof(node));
int i;
for(i=0; i<num_of_nodes; i+=1){
    node c;
    c.probability= *(probability+ i);
    c.symbol= *(SYMBOLS + i);
    c.left= NULL;
    c.right= NULL;
    *(leafs+i) = c;
}

node *root= (node*) malloc(sizeof(node)); // Root node which will be returned

while(num_of_nodes> 1){

    // 2) Find 2 nodes with lowest probabilities
    node *min_n1= (node*)malloc(sizeof(node));
    node *min_n2 = (node*)malloc(sizeof(node));

    *min_n1 = *find_min_node(leafs, num, min_n1);
    leafs = remove_node(leafs, min_n1, num); 
    num -= 1;

    *min_n2= *find_min_node(leafs, num, min_n2);
    leafs = remove_node(leafs, min_n2, num);
    num -= 1;

    // 3) Create parent node, and assign 2 min nodes as its children
            // add parent node to leafs, while its children have been removed from leafs
    node *new_node = (node*) malloc(sizeof(node));
    new_node->probabilty= min_n1->probability + min_n2->probability;
    new_node->left= min_n1;
    new_node->right= min_n2;

    leafs = add_node(leafs, new_node, num);
    num += 1;

    num_of_nodes -= 1;

    root = new_node;
}

return root;
