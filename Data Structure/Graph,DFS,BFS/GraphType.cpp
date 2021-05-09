#include <iostream>
#include "QueType.h"

template<class VertexType>
// Assumption: VertexType is a type for which the "=",
// "==", and "<<" operators are defined
class GraphType
{
public:
  GraphType();                  // Default of 50 vertices
  GraphType(int maxV);          // maxV <= 50
  ~GraphType();
//  void MakeEmpty();
//  bool IsEmpty() const;
//  bool IsFull() const;
  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  int WeightIs(VertexType, VertexType);
  void GetToVertices(VertexType, QueType<VertexType>&);
    void DeleteEdge(VertexType, VertexType);
    bool DepthFirstSearch_Recur(VertexType startVertex, VertexType endVertex);

//  void ClearMarks();
//  void MarkVertex(VertexType);
//  bool IsMarked(VertexType);
private:
  int numVertices;  //몇개 들어있냐
  int maxVertices;  //몇개가 최대냐
  VertexType* vertices; //Vertex 들어있는 array
  int edges[50][50];    // 2D array, weight 입력
  bool* marks;    // marks[i] is mark for vertices[i].
};



template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for  
//       marks and vertices.  numVertices is set to 0; 
//       maxVertices is set to 50.
{
  numVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for  
//       marks and vertices.  
//       numVertices is set to 0; maxVertices is set to maxV.
{
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}

template<class VertexType>
// Post: arrays for vertices and marks have been deallocated.
GraphType<VertexType>::~GraphType()
{
  delete [] vertices;
  delete [] marks;
}
const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set 
//       to NULL_EDGE.
//       numVertices has been incremented.
{
  vertices[numVertices] = vertex;

  for (int index = 0; index < numVertices; index++)
  {
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;
  }
  numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
// Post: Returns the index of vertex in vertices.
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;  
  return index;
}       

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
     VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
  edges[row][col] = weight;
}

//function     : vertex 사이에 연결된 edge를 제거한다.
//precondition : fromvertex와 tovertex가 존재해야한다. 삭제할 edge가 존재한다.
//postcondition: fromVertex와 toVertex사이의 edge가 제거된다.
template<class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex)
{
    int row;
    int col;
    
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    
    edges[row][col] = NULL_EDGE;
}

template<class VertexType>
int GraphType<VertexType>::WeightIs
     (VertexType fromVertex, VertexType toVertex)
// Post: Returns the weight associated with the edge 
//       (fromVertex, toVertex).
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  return edges[row][col];
}
template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, 
     QueType<VertexType>& adjVertices)
// Post: 
{
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      adjVertices.Enqueue(vertices[toIndex]);
}     



template<class VertexType>
bool GraphType<VertexType>::DepthFirstSearch_Recur(VertexType startVertex, VertexType endVertex)
{
    //base case
        // 1) vertex 값 = endvertex
        // 2) 더이상 갈 데가 없을때 --> edge열의 끝에 도달했을때 : return;
    //general case
        //start vertex
        //해당 vertex mark
        //vertex ! marked이면,
            //vertex index 행의 edges 검사
            //if edge != 0 --> edge 인덱스 가지고 새 search 돌리기
    QueType<VertexType> vertexQ;
    
    VertexType Vertex;
    Vertex = startVertex;
    
    //base case
    if(Vertex == endVertex)
    {
        std::cout << endVertex;
        return true;
    }

    GetToVertices(Vertex, vertexQ);
    while(!vertexQ.IsEmpty())
    {
        vertexQ.Dequeue(Vertex);
        if(Vertex != startVertex) // 왜 이 조건이 붙을까?
        {
            if(DepthFirstSearch_Recur(Vertex, endVertex) == true)
            {
                cout << " <- " << startVertex;
                return true;
            }
        }
    }
    
    return false;
}
