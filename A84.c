//  Reading and Displaying Book Information
#include <stdio.h>

struct Book
{
  char title[50];
  char author[50];
  int price;
};

void readBookInfo(struct Book *book)
{
  printf("Enter book title: ");
  scanf("%s", book->title);
  printf("Enter author name: ");
  scanf("%s", book->author);
  printf("Enter book price: ");
  scanf("%d", &book->price);
}

void displayBookInfo(struct Book book)
{
  printf("Book Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Price: %d\n", book.price);
}

int main()
{
  struct Book book;

  readBookInfo(&book);
  displayBookInfo(book);

  return 0;
}
