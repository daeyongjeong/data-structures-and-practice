#define MAX_VERTICES 25000

struct node
{
    int vertex;
    struct node *link;
};

struct node *adj[MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

typedef int Element;
// Global queue
typedef struct queue *queue_pointer;
typedef struct queue
{
    Element item;
    queue_pointer link;
} queue;
queue_pointer front, rear;

int build_graph(char *fname);
int insert_edge(int v, int w);
void get_close_vertices(int v, int k);
void bubble_sort(int a[], int array_size);

void addq(Element e);
Element deleteq();
int is_queue_empty();
int size_queue();