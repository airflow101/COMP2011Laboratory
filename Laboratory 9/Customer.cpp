#include <iostream>
#include <string.h>
#include "Customer.h"
using namespace std;


const char *customer_member[] = { "VIP", "Regular-member", "Non-member" };

Customer* new_customer(const char c_name[MAX_NAME_LENGTH+1], const char c_type[MAX_NAME_LENGTH+1]){
	// TODO1: Create new customer and set his/her name and membership accordingly, input validation is not needed.
  Customer *input_pointer = new Customer;
  strcpy(input_pointer->name, c_name);
  strcpy(input_pointer->type, c_type);
  input_pointer->next = nullptr;
  return input_pointer;
}

void insert_customer(Customer*& head, Customer* c){
	// TODO2: Insert the customer c into the queue according to his/her priority (VIP > Regular-member > Non-member)
  if(head == NULL){
    head = c;
    return;
  }

  if(strcmp(c->type, head->type) > 0){
    c->next = head;
    head = c;
    return;
  }

  Customer* queue_one_before_insert = head;

  while(strcmp(queue_one_before_insert->type, c->type)){
    if(queue_one_before_insert->next == nullptr){
      queue_one_before_insert->next = c;
      return;
    }
    if(!strcmp(queue_one_before_insert->type, c->type)){
      break;
    }
    queue_one_before_insert = queue_one_before_insert->next;
  }
// cout << c->type << endl;
// cout << strcmp(queue_one_before_insert->next->type, c->type) << endl;
  while(!strcmp(queue_one_before_insert->type, c->type)){
    if(queue_one_before_insert->next == nullptr){
      queue_one_before_insert->next = c;
      return;
    }
    else if(strcmp(queue_one_before_insert->next->type, c->type)){
      c->next = queue_one_before_insert->next;
      queue_one_before_insert->next = c;
      return;
    }
    queue_one_before_insert = queue_one_before_insert->next;
  }
}

void view_customers(const Customer* const head){
	// TODO3: View all customers in the queue, the output format should be:
	// name: name of the customer (tab or spaces) membership: membership of the customer
	// Note: display message like "Empty queue" if the queue is empty
	// Please refer to the output example in the lab manual page.
  if(head == nullptr){
    cout << "Current queue is empty." << '\n';
    return;
  }

  for(const Customer* customer = head; customer != nullptr; customer = customer->next){
    cout << "Name: " << customer->name << "\tMembership: " << customer->type << endl;
  }
}


Customer* dispatch_customer(Customer*& head){
	// TODO4: Dispatch the customer who has the highest priority
	// i.e. Remove the customer who are at the first place of the queue
	// Note that you need to return the pointer reference to the dispatched customer as well.
  Customer* dispatched = head;
  head = head->next;
  return dispatched;
}

void modify_customer_type(Customer*& head,  int pos, const char c_type[MAX_NAME_LENGTH+1]){
	// TODO5: Update the membership (c_type: [VIP|Regular-member|Non-member]) of the customer who is at the (pos)th place in the queue, then re-arrange the customer to a correct position
	// Note1: pos starts from 1
	// Note2: You don't need to do input validation for pos and c_type
	// Hint: The insert_patient function can be helpful
  Customer *modified_customer, *customer_before;
  int modified_sequence = 1;

  if(pos == 1){
    modified_customer = dispatch_customer(head);
    strcpy(modified_customer->type, c_type);
    insert_customer(head, modified_customer);
    return;
  }

  for(customer_before = head; modified_sequence < pos-1; modified_sequence++, customer_before = customer_before->next);
  modified_customer = customer_before->next;
  strcpy(modified_customer->type, c_type);
  customer_before->next = modified_customer->next;
  insert_customer(head, modified_customer);

}

void list_customers(const Customer* const head){
	const Customer* current = head;
	int i = 1;
	while(current != nullptr) {
		cout << i << ": " << current->name << endl;
		current = current->next;
		i++;
	}
}
