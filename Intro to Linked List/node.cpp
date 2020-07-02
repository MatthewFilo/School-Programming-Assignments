#include "node.h"
using namespace std;

node::node()
:data(0),next(0),prev(0) //Default value constructor, setting a node to be 0 values until values are implemented.
{

}

node::node(ElementType data1, node *next1, node *prev1) // Explicit value constructor
:data(data1),next(next1),prev(prev1) //Setting the parameters to equal whatever is inputed by the user.
{

}
