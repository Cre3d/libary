#include "library.h"
#include "stdafx.h"


void Library::AddBook(const Book &book)
{
	books.push_back(book);
}

void Library::Display() const
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << i + 1 << ". ";
		books[i].DisplayShort();
	}
}

Book& Library::operator[](size_t index)
{
	return books[index];
}

size_t Library::GetSize() const
{
	return books.size();
}
