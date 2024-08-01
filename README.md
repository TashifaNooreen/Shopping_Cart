Overview:
The project is a command-line based shopping cart system implemented using a doubly linked list in C programming language. It includes essential functionalities to add, remove, and manage items in a shopping cart and a wishlist, providing a seamless shopping experience.

Features:

Doubly Linked List Structure:

The shopping cart and wishlist are implemented using a doubly linked list, allowing efficient insertion, deletion, and traversal of items.
Item Management:

Add Items: Users can add items to the shopping cart or wishlist. Each item includes details such as name, quantity, and price.
Remove Items: Users can remove items from the cart or wishlist, allowing flexibility in managing the shopping session.
View Items: Users can view the current items in the cart and wishlist, including details of each item.
Wishlist Feature:

Add to Wishlist: Items can be added to the wishlist for future consideration.
Move to Cart: Users can move items from the wishlist to the shopping cart when they decide to purchase them.
Remove from Wishlist: Items can be removed from the wishlist if no longer needed.
Cart Operations:

Total Price Calculation: The total price of items in the cart is calculated, helping users keep track of their expenditure.
Checkout: A simple checkout process to finalize the purchase of items in the cart.
User Interface:

Command-line interface with intuitive prompts and menu options for ease of use.
Error handling for invalid inputs and operations.
Technical Details:
Data Structures:

Doubly Linked List: Each node contains pointers to the previous and next nodes, enabling traversal in both directions.
Item Node Structure: Contains fields for item name, quantity, and price.
Functions:

Add Item: Inserts a new item node at the end of the list.
Remove Item: Deletes a specified item node from the list.
Display Items: Traverses and displays all items in the list.
Move Item: Transfers an item node from the wishlist to the shopping cart.
Calculate Total: Computes the total cost of items in the cart.
