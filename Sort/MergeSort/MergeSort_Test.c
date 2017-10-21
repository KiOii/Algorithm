#include <stdio.h>
#include <memory.h>
/***************************************/
typedef int           mElemType;
typedef mElemType*    mArray;
typedef unsigned int  mIndex;
typedef mElemType*    mBuffer;
/***************************************/
void MergeSort(mArray S, mIndex begin,mIndex end);
void Merge(mArray S, mIndex begin,mIndex end);
/***************************************/
#define GetMid(_begin,_end) ( (((_begin)+(_end))/2) )
/***************************************/
int main()
{
	mElemType m[] = { 4,8,2,5,21,10,11,2,4,8 };
	MergeSort(m, 0, 9);
	return 0;
}

void MergeSort(mArray S, mIndex begin, mIndex end)
{
	if (begin < end)
	{
		MergeSort(S, begin, GetMid(begin,end));
		MergeSort(S, GetMid(begin, end) + 1, end);
		Merge(S, begin, end);

	}
}

void Merge(mArray S, mIndex begin, mIndex end)
{
	mIndex buffer_end   = end - begin;
	mIndex buffer_left  = 0;
	mIndex buffer_mid   = GetMid(buffer_left, buffer_end);
	mIndex buffer_right = buffer_mid + 1;
	mIndex s            = begin;
	mBuffer buffer = (mBuffer)malloc(sizeof(mElemType)*(buffer_end + 1)); // malloc
	memcpy(buffer, (S + begin), (sizeof(mElemType)*(buffer_end + 1)));
	
	while (buffer_left <= buffer_mid && buffer_right <= buffer_end)
	{
		buffer[buffer_left] < buffer[buffer_right] ? (S[s++] = buffer[buffer_left++]) : (S[s++] = buffer[buffer_right++]);
	}
	while (buffer_left <= buffer_mid)S[s++] = buffer[buffer_left++];
	while (buffer_right <= buffer_end)S[s++] = buffer[buffer_right++];
	
	free(buffer);					                     // free
}
