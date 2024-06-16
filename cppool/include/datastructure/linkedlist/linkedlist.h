#ifndef _CPPOOL_LINKEDLIST_H_
#define _CPPOOL_LINKEDLIST_H_

#include<stdint.h>
//Definition for singly-linked list.

#ifdef __cplusplus


template<typename T>
struct _SimplyListedNode
{
public:
	T data;
	LinkedNode* next;

	_SimplyListedNode();

};

template<typename T> using LinkedNode = struct _SimplyListedNode;
template<typename T> using LinkedList = struct _SimplyListedNode*;

#else

#endif // __cplusplus

#endif // !_CPPOOL_LINKEDLIST_H_
