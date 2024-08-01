#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a product
typedef struct Product {
    int id;
    char name[50];
    char description[200];
    float price;
    int quantity;
    struct Product *prev;
    struct Product *next;
} Product;

// Define a structure to represent the shopping cart
typedef struct {
    int totalItems;
    float totalCost;
    Product *head;
    Product *tail;
} ShoppingCart;

// Define a structure to represent the wishlist
typedef struct {
    Product *head;
    Product *tail;
} Wishlist;

// Function prototypes
void browseProducts();
void addToCart(ShoppingCart *cart, int id, char *name, char *description, float price, int quantity);
void removeFromCart(ShoppingCart *cart, int id);
void updateCart(ShoppingCart *cart, int id, int newQuantity);
void viewCart(ShoppingCart *cart);
void calculateTotal(ShoppingCart *cart);
void proceedToCheckout(ShoppingCart *cart);
Product* findProduct(Product *head, int id);
void addToWishlist(Wishlist *wishlist, int id, char *name, char *description, float price);
void viewWishlist(Wishlist *wishlist);
void moveWishlistToCart(Wishlist *wishlist, ShoppingCart *cart, int id);
void displayMenu();

int main() {
    ShoppingCart cart;
    cart.totalItems = 0;
    cart.totalCost = 0.0;
    cart.head = NULL;
    cart.tail = NULL;

    Wishlist wishlist;
    wishlist.head = NULL;
    wishlist.tail = NULL;

    int choice, id, quantity;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                browseProducts();
                break;
            case 2:
                printf("Enter product ID to add to cart: ");
                scanf("%d", &id);
                // Add product details based on the chosen ID
                switch (id) {
                    case 1: addToCart(&cart, id, "Laptop", "A high-performance laptop.", 100000.0, 1); break;
                    case 2: addToCart(&cart, id, "Headphones", "Noise-cancelling headphones.", 2000.0, 1); break;
                    case 3: addToCart(&cart, id, "Smartphone", "A latest model smartphone.", 18000.0, 1); break;
                    case 4: addToCart(&cart, id, "Monitor", "A 24-inch monitor.", 4000.0, 1); break;
                    case 5: addToCart(&cart, id, "Keyboard", "A mechanical keyboard.", 500.0, 1); break;
                    case 6: addToCart(&cart, id, "Mouse", "A Mouse.", 700.0, 1); break;
                    case 7: addToCart(&cart, id, "Tablet", "A brand new Tablet.", 50000.0, 1); break;
                    case 8: addToCart(&cart, id, "Printer", "A wireless printer.", 25000.0, 1); break;
                    case 9: addToCart(&cart, id, "Smart Watch", "A feature-packed smartwatch.", 4500.0, 1); break;
                    case 10: addToCart(&cart, id, "Router", "A high-speed router.", 30500.0, 1); break;
                    case 11: addToCart(&cart, id, "TV", "A high-definition television.", 60000.0, 1); break;
                    case 12: addToCart(&cart, id, "Camera", "A professional camera.", 45000.0, 1); break;
                    case 13: addToCart(&cart, id, "Speaker", "High-quality speakers.", 7000.0, 1); break;
                    case 14: addToCart(&cart, id, "Hard Drive", "1TB external hard drive.", 5000.0, 1); break;
                    case 15: addToCart(&cart, id, "SSD", "Solid state drive for faster storage.", 8000.0, 1); break;
                    case 16: addToCart(&cart, id, "Flash Drive", "Portable USB flash drive.", 1000.0, 1); break;
                    case 17: addToCart(&cart, id, "External Battery", "Portable external battery pack.", 3000.0, 1); break;
                    case 18: addToCart(&cart, id, "Laptop Stand", "Ergonomic laptop stand.", 1500.0, 1); break;
                    case 19: addToCart(&cart, id, "HDMI Cable", "High-speed HDMI cable.", 400.0, 1); break;
                    case 20: addToCart(&cart, id, "USB Hub", "USB hub for additional ports.", 900.0, 1); break;
                    case 21: addToCart(&cart, id, "Gaming Console", "Latest gaming console.", 40000.0, 1); break;
                    case 22: addToCart(&cart, id, "Gamepad", "Controller for gaming.", 2500.0, 1); break;
                    case 23: addToCart(&cart, id, "VR Headset", "Virtual reality headset.", 25000.0, 1); break;
                    case 24: addToCart(&cart, id, "Drone", "Remote-controlled drone.", 35000.0, 1); break;
                    case 25: addToCart(&cart, id, "Action Camera", "Compact action camera.", 20000.0, 1); break;
                    case 26: addToCart(&cart, id, "Smart Home Hub", "Central hub for smart home devices.", 12000.0, 1); break;
                    case 27: addToCart(&cart, id, "Smart Bulb", "Wireless smart light bulb.", 1500.0, 1); break;
                    case 28: addToCart(&cart, id, "Smart Thermostat", "Thermostat for smart home control.", 10000.0, 1); break;
                    case 29: addToCart(&cart, id, "Doorbell Camera", "Smart doorbell with camera.", 8000.0, 1); break;
                    case 30: addToCart(&cart, id, "Security Camera", "Indoor/outdoor security camera.", 15000.0, 1); break;
                    case 31: addToCart(&cart, id, "Microwave", "Countertop microwave oven.", 12000.0, 1); break;
                    case 32: addToCart(&cart, id, "Refrigerator", "Large capacity refrigerator.", 50000.0, 1); break;
                    case 33: addToCart(&cart, id, "Washing Machine", "Front-load washing machine.", 40000.0, 1); break;
                    case 34: addToCart(&cart, id, "Dishwasher", "Built-in dishwasher.", 35000.0, 1); break;
                    case 35: addToCart(&cart, id, "Coffee Maker", "Automatic coffee maker.", 7000.0, 1); break;
                    case 36: addToCart(&cart, id, "Blender", "Kitchen blender for smoothies.", 3000.0, 1); break;
                    case 37: addToCart(&cart, id, "Toaster", "2-slice toaster for bread.", 2500.0, 1); break;
                    case 38: addToCart(&cart, id, "Vacuum Cleaner", "Bagless upright vacuum cleaner.", 15000.0, 1); break;
                    case 39: addToCart(&cart, id, "Air Purifier", "HEPA air purifier.", 10000.0, 1); break;
                    case 40: addToCart(&cart, id, "Heater", "Electric space heater.", 5000.0, 1); break;
                    case 41: addToCart(&cart, id, "Fan", "Oscillating tower fan.", 3000.0, 1); break;
                    case 42: addToCart(&cart, id, "Air Conditioner", "Split air conditioning unit.", 30000.0, 1); break;
                    case 43: addToCart(&cart, id, "Water Purifier", "RO water purifier.", 15000.0, 1); break;
                    case 44: addToCart(&cart, id, "Fitness Tracker", "Wearable fitness tracker.", 5000.0, 1); break;
                    case 45: addToCart(&cart, id, "Treadmill", "Home treadmill for exercise.", 50000.0, 1); break;
                    case 46: addToCart(&cart, id, "Exercise Bike", "Indoor stationary exercise bike.", 25000.0, 1); break;
                    case 47: addToCart(&cart, id, "Yoga Mat", "Non-slip yoga mat.", 2000.0, 1); break;
                    case 48: addToCart(&cart, id, "Dumbbells", "Adjustable dumbbells.", 4000.0, 1); break;
                    case 49: addToCart(&cart, id, "Resistance Bands", "Exercise resistance bands set.", 1000.0, 1); break;
                    case 50: addToCart(&cart, id, "Jump Rope", "Speed jump rope for cardio.", 500.0, 1); break;
                    case 51: addToCart(&cart, id, "Bicycle", "Adult bicycle for commuting.", 30000.0, 1); break;
                    case 52: addToCart(&cart, id, "Helmet", "Safety helmet for cycling.", 2000.0, 1); break;
                    case 53: addToCart(&cart, id, "Tent", "Camping tent for outdoor shelter.", 10000.0, 1); break;
                    case 54: addToCart(&cart, id, "Sleeping Bag", "Warm sleeping bag for camping.", 5000.0, 1); break;
                    case 55: addToCart(&cart, id, "Backpack", "Hiking backpack for outdoor adventures.", 3000.0, 1); break;
                    case 56: addToCart(&cart, id, "Water Bottle", "Reusable water bottle.", 500.0, 1); break;
                    case 57: addToCart(&cart, id, "Hiking Boots", "Durable hiking boots.", 8000.0, 1); break;
                    case 58: addToCart(&cart, id, "Camping Stove", "Portable camping stove.", 3000.0, 1); break;
                    case 59: addToCart(&cart, id, "Lantern", "LED camping lantern.", 2000.0, 1); break;
                    case 60: addToCart(&cart, id, "Fishing Rod", "Fishing rod for angling.", 4000.0, 1); break;
                    case 61: addToCart(&cart, id, "Tennis Racket", "Professional tennis racket.", 7000.0, 1); break;
                    case 62: addToCart(&cart, id, "Golf Clubs", "Complete set of golf clubs.", 50000.0, 1); break;
                    case 63: addToCart(&cart, id, "Basketball", "Official size basketball.", 2000.0, 1); break;
                    case 64: addToCart(&cart, id, "Football", "Standard size football.", 1500.0, 1); break;
                    case 65: addToCart(&cart, id, "Cricket Bat", "Cricket bat for batting.", 5000.0, 1); break;
                    case 66: addToCart(&cart, id, "Badminton Set", "Complete badminton set.", 3000.0, 1); break;
                    case 67: addToCart(&cart, id, "Table Tennis Set", "Table tennis set with paddles and balls.", 4000.0, 1); break;
                    case 68: addToCart(&cart, id, "Board Game", "Classic board game.", 2000.0, 1); break;
                    case 69: addToCart(&cart, id, "Puzzle", "Jigsaw puzzle for leisure.", 1000.0, 1); break;
                    case 70: addToCart(&cart, id, "Doll", "Collectible doll for play.", 1500.0, 1); break;
                    case 71: addToCart(&cart, id, "Action Figure", "Action figure toy.", 2000.0, 1); break;
                    case 72: addToCart(&cart, id, "Building Blocks", "Educational building blocks.", 3000.0, 1); break;
                    case 73: addToCart(&cart, id, "Toy Car", "Remote-controlled toy car.", 2500.0, 1); break;
                    case 74: addToCart(&cart, id, "Remote Control Car", "High-speed remote control car.", 5000.0, 1); break;
                    case 75: addToCart(&cart, id, "Toy Train Set", "Electric toy train set.", 6000.0, 1); break;
                    case 76: addToCart(&cart, id, "Storybook", "Children's storybook.", 500.0, 1); break;
                    case 77: addToCart(&cart, id, "Novel", "Bestselling novel.", 1000.0, 1); break;
                    case 78: addToCart(&cart, id, "Magazine", "Popular magazine subscription.", 300.0, 1); break;
                    case 79: addToCart(&cart, id, "Coloring Book", "Creative coloring book for kids.", 200.0, 1); break;
                    case 80: addToCart(&cart, id, "Notebook", "Notebook for writing.", 100.0, 1); break;
                    case 81: addToCart(&cart, id, "Pen", "Ballpoint pen.", 50.0, 1); break;
                    case 82: addToCart(&cart, id, "Pencil", "Wooden pencil.", 20.0, 1); break;
                    case 83: addToCart(&cart, id, "Marker", "Permanent marker.", 100.0, 1); break;
                    case 84: addToCart(&cart, id, "Eraser", "Rubber eraser.", 10.0, 1); break;
                    case 85: addToCart(&cart, id, "Sharpener", "Pencil sharpener.", 15.0, 1); break;
                    case 86: addToCart(&cart, id, "Ruler", "12-inch ruler.", 30.0, 1); break;
                    case 87: addToCart(&cart, id, "Calculator", "Scientific calculator.", 500.0, 1); break;
                    case 88: addToCart(&cart, id, "School Bag", "School backpack.", 1000.0, 1); break;
                    case 89: addToCart(&cart, id, "Lunch Box", "Insulated lunch box.", 300.0, 1); break;
                    case 90: addToCart(&cart, id, "Water Bottle", "School water bottle.", 200.0, 1); break;
                    case 91: addToCart(&cart, id, "Uniform", "School uniform set.", 1500.0, 1); break;
                    case 92: addToCart(&cart, id, "Shoes", "School shoes.", 2000.0, 1); break;
                    case 93: addToCart(&cart, id, "Socks", "Cotton socks.", 100.0, 1); break;
                    case 94: addToCart(&cart, id, "Belt", "Leather belt.", 300.0, 1); break;
                    case 95: addToCart(&cart, id, "Tie", "Silk tie.", 200.0, 1); break;
                    case 96: addToCart(&cart, id, "Cap", "Baseball cap.", 500.0, 1); break;
                    case 97: addToCart(&cart, id, "Sunglasses", "Polarized sunglasses.", 1500.0, 1); break;
                    case 98: addToCart(&cart, id, "Watch", "Wrist Watch.", 5000.0, 1); break;
                    case 99: addToCart(&cart, id, "Wallet", "Leather wallet.", 1000.0, 1); break;
                    case 100: addToCart(&cart, id, "Keychain", "Metal keychain.", 200.0, 1); break;
                    



                    default: printf("Invalid product ID.\n");
                }
                break;
            case 3:
                printf("Enter product ID to remove from cart: ");
                scanf("%d", &id);
                removeFromCart(&cart, id);
                break;
            case 4:
                viewCart(&cart);
                printf("\nEnter product ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateCart(&cart, id, quantity);
                break;
            case 5:
                viewCart(&cart);
                break;
            case 6:
                printf("Enter product ID to add to wishlist: ");
                scanf("%d", &id);
                // Add product details based on the chosen ID
                switch (id) {
                    case 1: addToWishlist(&wishlist, id, "Laptop", "A high-performance laptop.", 100000.0); break;
                    case 2: addToWishlist(&wishlist, id, "Headphones", "Noise-cancelling headphones.", 2000.0); break;
                    case 3: addToWishlist(&wishlist, id, "Smartphone", "A latest model smartphone.", 18000.0); break;
                    case 4: addToWishlist(&wishlist, id, "Monitor", "A 24-inch monitor.", 4000.0); break;
                    case 5: addToWishlist(&wishlist, id, "Keyboard", "A mechanical keyboard.", 500.0); break;
                    case 6: addToWishlist(&wishlist, id, "Mouse", "A Mouse.", 700.0); break;
                    case 7: addToWishlist(&wishlist, id, "Tablet", "A brand new Tablet.", 50000.0); break;
                    case 8: addToWishlist(&wishlist, id, "Printer", "A wireless printer.", 25000.0); break;
                    case 9: addToWishlist(&wishlist, id, "Smart Watch", "A feature-packed smartwatch.", 4500.0); break;
                    case 10: addToWishlist(&wishlist, id, "Router", "A high-speed router.", 30500.0); break;
                    case 11: addToWishlist(&wishlist, id, "TV", "A large screen television.", 60000.0); break;
                    case 12: addToWishlist(&wishlist, id, "Camera", "A professional camera.", 45000.0); break;
                    case 13: addToWishlist(&wishlist, id, "Speaker", "High-quality speakers.", 7000.0); break;
                    case 14: addToWishlist(&wishlist, id, "Hard Drive", "External hard drive.", 5000.0); break;
                    case 15: addToWishlist(&wishlist, id, "SSD", "Solid State Drive.", 8000.0); break;
                    case 16: addToWishlist(&wishlist, id, "Flash Drive", "USB flash drive.", 1000.0); break;
                    case 17: addToWishlist(&wishlist, id, "External Battery", "Portable battery pack.", 3000.0); break;
                    case 18: addToWishlist(&wishlist, id, "Laptop Stand", "Adjustable laptop stand.", 1500.0); break;
                    case 19: addToWishlist(&wishlist, id, "HDMI Cable", "High-speed HDMI cable.", 400.0); break;
                    case 20: addToWishlist(&wishlist, id, "USB Hub", "Multi-port USB hub.", 900.0); break;
                    case 21: addToWishlist(&wishlist, id, "Gaming Console", "Next-gen gaming console.", 40000.0); break;
                    case 22: addToWishlist(&wishlist, id, "Gamepad", "Wireless game controller.", 2500.0); break;
                    case 23: addToWishlist(&wishlist, id, "VR Headset", "Virtual reality headset.", 25000.0); break;
                    case 24: addToWishlist(&wishlist, id, "Drone", "Quadcopter drone.", 35000.0); break;
                    case 25: addToWishlist(&wishlist, id, "Action Camera", "Waterproof action camera.", 20000.0); break;
                    case 26: addToWishlist(&wishlist, id, "Smart Home Hub", "Central smart home controller.", 12000.0); break;
                    case 27: addToWishlist(&wishlist, id, "Smart Bulb", "Wireless smart bulb.", 1500.0); break;
                    case 28: addToWishlist(&wishlist, id, "Smart Thermostat", "Programmable thermostat.", 10000.0); break;
                    case 29: addToWishlist(&wishlist, id, "Doorbell Camera", "Smart doorbell with camera.", 8000.0); break;
                    case 30: addToWishlist(&wishlist, id, "Security Camera", "Home security camera system.", 15000.0); break;
                    case 31: addToWishlist(&wishlist, id, "Microwave", "Countertop microwave oven.", 12000.0); break;
                    case 32: addToWishlist(&wishlist, id, "Refrigerator", "Large capacity refrigerator.", 50000.0); break;
                    case 33: addToWishlist(&wishlist, id, "Washing Machine", "Front-load washing machine.", 40000.0); break;
                    case 34: addToWishlist(&wishlist, id, "Dishwasher", "Built-in dishwasher.", 35000.0); break;
                    case 35: addToWishlist(&wishlist, id, "Coffee Maker", "Automatic coffee machine.", 7000.0); break;
                    case 36: addToWishlist(&wishlist, id, "Blender", "High-performance blender.", 3000.0); break;
                    case 37: addToWishlist(&wishlist, id, "Toaster", "2-slice toaster.", 2500.0); break;
                    case 38: addToWishlist(&wishlist, id, "Vacuum Cleaner", "Robotic vacuum cleaner.", 15000.0); break;
                    case 39: addToWishlist(&wishlist, id, "Air Purifier", "HEPA air purifier.",10000.0); break;
                    case 40: addToWishlist(&wishlist, id, "Heater", "Electric space heater.", 5000.0);break;
                    case 41: addToWishlist(&wishlist, id, "Fan", "Tower fan with remote.", 3000.0); break;
                    case 42: addToWishlist(&wishlist, id, "Air Conditioner", "Split air conditioner.", 30000.0); break;
                    case 43: addToWishlist(&wishlist, id, "Water Purifier", "Reverse osmosis water filter.", 15000.0); break;
                    case 44: addToWishlist(&wishlist, id, "Fitness Tracker", "Activity tracker wristband.", 5000.0); break;
                    case 45: addToWishlist(&wishlist, id, "Treadmill", "Home treadmill machine.", 50000.0); break;
                    case 46: addToWishlist(&wishlist, id, "Exercise Bike", "Stationary exercise bike.", 25000.0); break;
                    case 47: addToWishlist(&wishlist, id, "Yoga Mat", "Non-slip yoga mat.", 2000.0); break;
                    case 48: addToWishlist(&wishlist, id, "Dumbbells", "Adjustable dumbbell set.", 4000.0); break;
                    case 49: addToWishlist(&wishlist, id, "Resistance Bands", "Elastic resistance bands.", 1000.0); break;
                    case 50: addToWishlist(&wishlist, id, "Jump Rope", "Speed jump rope.", 500.0); break;
                    case 51: addToWishlist(&wishlist, id, "Bicycle", "High-quality bicycle for outdoor rides.", 30000.0); break;
                    case 52: addToWishlist(&wishlist, id, "Helmet", "Protective helmet for cyclists.", 2000.0); break;
                    case 53: addToWishlist(&wishlist, id, "Tent", "Portable shelter for camping.", 10000.0); break;
                    case 54: addToWishlist(&wishlist, id, "Sleeping Bag", "Insulated sleeping bag.", 5000.0); break;
                    case 55: addToWishlist(&wishlist, id, "Backpack", "Durable hiking backpack.", 3000.0); break;
                    case 56: addToWishlist(&wishlist, id, "Water Bottle", "Reusable water bottle.", 500.0); break;
                    case 57: addToWishlist(&wishlist, id, "Hiking Boots", "Sturdy hiking boots.", 8000.0); break;
                    case 58: addToWishlist(&wishlist, id, "Camping Stove", "Portable camping stove.", 3000.0); break;
                    case 59: addToWishlist(&wishlist, id, "Lantern", "LED camping lantern.", 2000.0); break;
                    case 60: addToWishlist(&wishlist, id, "Fishing Rod", "Telescopic fishing rod.", 4000.0); break;
                    case 61: addToWishlist(&wishlist, id, "Tennis Racket", "Carbon fiber tennis racket.", 7000.0); break;
                    case 62: addToWishlist(&wishlist, id, "Golf Clubs", "Complete golf club set.", 50000.0); break;
                    case 63: addToWishlist(&wishlist, id, "Basketball", "Indoor/outdoor basketball.", 2000.0); break;
                    case 64: addToWishlist(&wishlist, id, "Football", "Official size football.", 1500.0); break;
                    case 65: addToWishlist(&wishlist, id, "Cricket Bat", "English willow cricket bat.", 5000.0); break;
                    case 66: addToWishlist(&wishlist, id, "Badminton Set", "Professional badminton set.", 3000.0); break;
                    case 67: addToWishlist(&wishlist, id, "Table Tennis Set", "Table tennis racket set.", 4000.0); break;
                    case 68: addToWishlist(&wishlist, id, "Board Game", "Classic board game.", 2000.0); break;
                    case 69: addToWishlist(&wishlist, id, "Puzzle", "Jigsaw puzzle for all ages.", 1000.0); break;
                    case 70: addToWishlist(&wishlist, id, "Doll", "Collectible fashion doll.", 1500.0); break;
                    case 71: addToWishlist(&wishlist, id, "Action Figure", "Popular action figure.", 2000.0); break;
                    case 72: addToWishlist(&wishlist, id, "Building Blocks", "Educational building blocks.", 3000.0); break;
                    case 73: addToWishlist(&wishlist, id, "Toy Car", "Remote control toy car.", 2500.0); break;
                    case 74: addToWishlist(&wishlist, id, "Remote Control Car", "RC drift car.", 5000.0); break;
                    case 75: addToWishlist(&wishlist, id, "Toy Train Set", "Classic toy train set.", 6000.0); break;
                    case 76: addToWishlist(&wishlist, id, "Storybook", "Children's storybook.", 500.0); break;
                    case 77: addToWishlist(&wishlist, id, "Novel", "Bestselling novel.", 1000.0); break;
                    case 78: addToWishlist(&wishlist, id, "Magazine", "Monthly magazine subscription.", 300.0); break;
                    case 79: addToWishlist(&wishlist, id, "Coloring Book", "Adult coloring book.", 200.0); break;
                    case 80: addToWishlist(&wishlist, id, "Notebook", "Spiral-bound notebook.", 100.0); break;
                    case 81: addToWishlist(&wishlist, id, "Pen", "Ballpoint pen.", 50.0); break;
                    case 82: addToWishlist(&wishlist, id, "Pencil", "Wooden graphite pencil.", 20.0); break;
                    case 83: addToWishlist(&wishlist, id, "Marker", "Permanent marker.", 100.0); break;
                    case 84: addToWishlist(&wishlist, id, "Eraser", "Rubber eraser.", 10.0); break;
                    case 85: addToWishlist(&wishlist, id, "Sharpener", "Pencil sharpener.", 15.0); break;
                    case 86: addToWishlist(&wishlist, id, "Ruler", "12-inch ruler.", 30.0); break;
                    case 87: addToWishlist(&wishlist, id, "Calculator", "Scientific calculator.", 500.0); break;
                    case 88: addToWishlist(&wishlist, id, "School Bag", "Backpack for school.", 1000.0); break;
                    case 89: addToWishlist(&wishlist, id, "Lunch Box", "Insulated lunch box.", 300.0); break;
                    case 90: addToWishlist(&wishlist, id, "Water Bottle", "Kids' water bottle.", 200.0); break;
                    case 91: addToWishlist(&wishlist, id, "Uniform", "School uniform set.", 1500.0); break;
                    case 92: addToWishlist(&wishlist, id, "Shoes", "School shoes.", 2000.0); break;
                    case 93: addToWishlist(&wishlist, id, "Socks", "Cotton school socks.", 100.0); break;
                    case 94: addToWishlist(&wishlist, id, "Belt", "Leather belt.", 300.0); break;
                    case 95: addToWishlist(&wishlist, id, "Tie", "Silk necktie.", 200.0); break;
                    case 96: addToWishlist(&wishlist, id, "Cap", "Baseball cap.", 500.0); break;
                    case 97: addToWishlist(&wishlist, id, "Sunglasses", "Polarized sunglasses.", 1500.0); break;
                    case 98: addToWishlist(&wishlist, id, "Watch", "Stylish wristwatch.", 2500.0); break;
                    case 99: addToWishlist(&wishlist, id, "Wallet", "Leather wallet.", 1000.0); break;
                    case 100: addToWishlist(&wishlist, id, "Keychain", "Metal keychain.", 200.0); break;


                    default: printf("Invalid product ID.\n");
                }
                break;
            case 7:
                viewWishlist(&wishlist);
                break;
            case 8:
                viewWishlist(&wishlist);
                printf("\nEnter product ID to move from wishlist to cart: ");
                scanf("%d", &id);
                moveWishlistToCart(&wishlist, &cart, id);
                break;
            case 9:
                proceedToCheckout(&cart);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Browse Products\n");
    printf("2. Add to Cart\n");
    printf("3. Remove from Cart\n");
    printf("4. Update Cart\n");
    printf("5. View Cart\n");
    printf("6. Add to Wishlist\n");
    printf("7. View Wishlist\n");
    printf("8. Move from Wishlist to Cart\n");
    printf("9. Proceed to Checkout\n");
}

void browseProducts() {
    printf("Available products:\n");
    printf("1. Laptop - Rs.100000.00\n");
    printf("2. Headphones - Rs.2000.00\n");
    printf("3. Smartphone - Rs.18000.00\n");
    printf("4. Monitor - Rs.4000.00\n");
    printf("5. Keyboard - Rs.500.00\n");
    printf("6. Mouse - Rs.700.00\n");
    printf("7. Tablet - Rs.50000.00\n");
    printf("8. Printer - Rs.25000.00\n");
    printf("9. Smart Watch - Rs.4500.00\n");
    printf("10. Router - Rs.30500.00\n");
    printf("11. TV - Rs.60000.00\n");
    printf("12. Camera - Rs.45000.00\n");
    printf("13. Speaker - Rs.7000.00\n");
    printf("14. Hard Drive - Rs.5000.00\n");
    printf("15. SSD - Rs.8000.00\n");
    printf("16. Flash Drive - Rs.1000.00\n");
    printf("17. External Battery - Rs.3000.00\n");
    printf("18. Laptop Stand - Rs.1500.00\n");
    printf("19. HDMI Cable - Rs.400.00\n");
    printf("20. USB Hub - Rs.900.00\n");
    printf("21. Gaming Console - Rs.40000.00\n");
    printf("22. Gamepad - Rs.2500.00\n");
    printf("23. VR Headset - Rs.25000.00\n");
    printf("24. Drone - Rs.35000.00\n");
    printf("25. Action Camera - Rs.20000.00\n");
    printf("26. Smart Home Hub - Rs.12000.00\n");
    printf("27. Smart Bulb - Rs.1500.00\n");
    printf("28. Smart Thermostat - Rs.10000.00\n");
    printf("29. Doorbell Camera - Rs.8000.00\n");
    printf("30. Security Camera - Rs.15000.00\n");
    printf("31. Microwave - Rs.12000.00\n");
    printf("32. Refrigerator - Rs.50000.00\n");
    printf("33. Washing Machine - Rs.40000.00\n");
    printf("34. Dishwasher - Rs.35000.00\n");
    printf("35. Coffee Maker - Rs.7000.00\n");
    printf("36. Blender - Rs.3000.00\n");
    printf("37. Toaster - Rs.2500.00\n");
    printf("38. Vacuum Cleaner - Rs.15000.00\n");
    printf("39. Air Purifier - Rs.10000.00\n");
    printf("40. Heater - Rs.5000.00\n");
    printf("41. Fan - Rs.3000.00\n");
    printf("42. Air Conditioner - Rs.30000.00\n");
    printf("43. Water Purifier - Rs.15000.00\n");
    printf("44. Fitness Tracker - Rs.5000.00\n");
    printf("45. Treadmill - Rs.50000.00\n");
    printf("46. Exercise Bike - Rs.25000.00\n");
    printf("47. Yoga Mat - Rs.2000.00\n");
    printf("48. Dumbbells - Rs.4000.00\n");
    printf("49. Resistance Bands - Rs.1000.00\n");
    printf("50. Jump Rope - Rs.500.00\n");
    printf("51. Bicycle - Rs.30000.00\n");
    printf("52. Helmet - Rs.2000.00\n");
    printf("53. Tent - Rs.10000.00\n");
    printf("54. Sleeping Bag - Rs.5000.00\n");
    printf("55. Backpack - Rs.3000.00\n");
    printf("56. Water Bottle - Rs.500.00\n");
    printf("57. Hiking Boots - Rs.8000.00\n");
    printf("58. Camping Stove - Rs.3000.00\n");
    printf("59. Lantern - Rs.2000.00\n");
    printf("60. Fishing Rod - Rs.4000.00\n");
    printf("61. Tennis Racket - Rs.7000.00\n");
    printf("62. Golf Clubs - Rs.50000.00\n");
    printf("63. Basketball - Rs.2000.00\n");
    printf("64. Football - Rs.1500.00\n");
    printf("65. Cricket Bat - Rs.5000.00\n");
    printf("66. Badminton Set - Rs.3000.00\n");
    printf("67. Table Tennis Set - Rs.4000.00\n");
    printf("68. Board Game - Rs.2000.00\n");
    printf("69. Puzzle - Rs.1000.00\n");
    printf("70. Doll - Rs.1500.00\n");
    printf("71. Action Figure - Rs.2000.00\n");
    printf("72. Building Blocks - Rs.3000.00\n");
    printf("73. Toy Car - Rs.2500.00\n");
    printf("74. Remote Control Car - Rs.5000.00\n");
    printf("75. Toy Train Set - Rs.6000.00\n");
    printf("76. Storybook - Rs.500.00\n");
    printf("77. Novel - Rs.1000.00\n");
    printf("78. Magazine - Rs.300.00\n");
    printf("79. Coloring Book - Rs.200.00\n");
    printf("80. Notebook - Rs.100.00\n");
    printf("81. Pen - Rs.50.00\n");
    printf("82. Pencil - Rs.20.00\n");
    printf("83. Marker - Rs.100.00\n");
    printf("84. Eraser - Rs.10.00\n");
    printf("85. Sharpener - Rs.15.00\n");
    printf("86. Ruler - Rs.30.00\n");
    printf("87. Calculator - Rs.500.00\n");
    printf("88. School Bag - Rs.1000.00\n");
    printf("89. Lunch Box - Rs.300.00\n");
    printf("90. Water Bottle - Rs.200.00\n");
    printf("91. Uniform - Rs.1500.00\n");
    printf("92. Shoes - Rs.2000.00\n");
    printf("93. Socks - Rs.100.00\n");
    printf("94. Belt - Rs.300.00\n");
    printf("95. Tie - Rs.200.00\n");
    printf("96. Cap - Rs.500.00\n");
    printf("97. Sunglasses - Rs.1500.00\n");
    printf("98. Watch - Rs.2500.00\n");
    printf("99. Wallet - Rs.1000.00\n");
    printf("100. Keychain - Rs.200.00\n");
}

void addToCart(ShoppingCart *cart, int id, char *name, char *description, float price, int quantity) {
    Product *newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    strcpy(newProduct->description, description);
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->prev = cart->tail;
    newProduct->next = NULL;

    if(cart->head == NULL) {
        cart->head = newProduct;
        cart->tail = newProduct;
    } else {
        cart->tail->next = newProduct;
        cart->tail = newProduct;
    }

    cart->totalItems += quantity;
    cart->totalCost += price * quantity;
    printf("Added %s to the cart.\n", name);
}

void removeFromCart(ShoppingCart *cart, int id) {
    Product *product = findProduct(cart->head, id);
    if(product == NULL) {
        printf("Product not found in the cart.\n");
        return;
    }

    if(product->prev != NULL) {
        product->prev->next = product->next;
    } else {
        cart->head = product->next;
    }

    if(product->next != NULL) {
        product->next->prev = product->prev;
    } else {
        cart->tail = product->prev;
    }

    cart->totalItems -= product->quantity;
    cart->totalCost -= product->price * product->quantity;
    free(product);
    printf("Removed product from the cart.\n");
}

void updateCart(ShoppingCart *cart, int id, int newQuantity) {
    Product *product = findProduct(cart->head, id);
    if(product == NULL) {
        printf("Product not found in the cart.\n");
        return;
    }

    cart->totalItems += newQuantity - product->quantity;
    cart->totalCost += (newQuantity - product->quantity) * product->price;
    product->quantity = newQuantity;
    printf("Updated product quantity in the cart.\n");
}

void viewCart(ShoppingCart *cart) {
    if(cart->head == NULL) {
        printf("Your cart is empty.\n");
        return;
    }

    Product *current = cart->head;
    printf("Your cart contains:\n");
    while(current != NULL) {
        printf("\nProduct ID: %d, \nName: %s, \nQuantity: %d, \nPrice: %.2f, \nTotal: %.2f\n",
               current->id, current->name, current->quantity, current->price, current->quantity * current->price);
        current = current->next;
    }
    calculateTotal(cart);
}

void calculateTotal(ShoppingCart *cart) {
    printf("\n\nTotal items: %d, \nTotal cost: %.2f\n", cart->totalItems, cart->totalCost);
}

void proceedToCheckout(ShoppingCart *cart) {
    printf("\nProceeding to checkout...\n");
    calculateTotal(cart);
    // Here you would add payment and shipping information handling
    printf("\nThank you for your purchase!\n");
}

Product* findProduct(Product *head, int id) {
    Product *current = head;
    while(current != NULL) {
        if(current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addToWishlist(Wishlist *wishlist, int id, char *name, char *description, float price) {
    Product *newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    strcpy(newProduct->description, description);
    newProduct->price = price;
    newProduct->quantity = 1;
    newProduct->prev = wishlist->tail;
    newProduct->next = NULL;

    if(wishlist->head == NULL) {
        wishlist->head = newProduct;
        wishlist->tail = newProduct;
    } else {
        wishlist->tail->next = newProduct;
        wishlist->tail = newProduct;
    }

    printf("Added %s to the wishlist.\n", name);
}

void viewWishlist(Wishlist *wishlist) {
    if(wishlist->head == NULL) {
        printf("Your wishlist is empty.\n");
        return;
    }

    Product *current = wishlist->head;
    printf("Your wishlist contains:\n");
    while(current != NULL) {
        printf("\nProduct ID: %d, \nName: %s, \nPrice: %.2f\n",
               current->id, current->name, current->price);
        current = current->next;
    }
}

void moveWishlistToCart(Wishlist *wishlist, ShoppingCart *cart, int id) {
    Product *product = findProduct(wishlist->head, id);
    if(product == NULL) {
        printf("Product not found in the wishlist.\n");
        return;
    }

    addToCart(cart, product->id, product->name, product->description, product->price, product->quantity);
    // Remove product from wishlist
    if(product->prev != NULL) {
        product->prev->next = product->next;
    } else {
        wishlist->head = product->next;
    }

    if(product->next != NULL) {
        product->next->prev = product->prev;
    } else {
        wishlist->tail = product->prev;
    }

    free(product);
    printf("Moved product from wishlist to cart.\n");
}
