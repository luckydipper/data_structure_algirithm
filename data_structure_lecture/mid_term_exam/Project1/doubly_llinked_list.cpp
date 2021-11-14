struct Node
{
	int info;
	Node* next;
	Node* before;
	Node();
	Node(int info);
};

Node::Node() :next(nullptr), before(nullptr) { info = 0; }

Node::Node(int info) : info(info), next(nullptr), before(nullptr) { ; }


class LinkedList
{
private:
	const Node* const front_dumy = new Node();
	const Node* const back_dumy  = new Node();
public:
	LinkedList();
	~LinkedList();
	void insert_item() const;
	
};

LinkedList::~LinkedList()
{
	Node* iterator = const_cast<Node*>( front_dumy );
	while (iterator != nullptr)
	{
		Node* temp = iterator;
		iterator = iterator->next;
		delete temp;
	}
}

