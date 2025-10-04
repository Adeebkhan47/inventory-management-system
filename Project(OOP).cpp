#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h> // header for sleep function
#include <ctime>
#include <fstream> //header for file handling
#include <limits>  //for applying checkers
using namespace std;
// ========================== Product Details Class ==================

class productData
{
private:
  string name;
  double price;
  int quantity;
  string catagory;
  int productID;
  static int idStart;

public:
  productData() : productID(idStart++){}

  // Setter and Getter Functions
  void setName(string name) { this->name = name; }
  void setPrice(double price) { this->price = price; }
  void setQuantity(int quan) { this->quantity = quan; }
  void setCatagory(string catagory) { this->catagory = catagory; }

  // getter Functions
  string getName() const { return name; }
  double getPrice() const { return price; }
  int getQuantity() const { return quantity; }
  string getCatagory() const { return catagory; }
  int getID() const { return productID; }
};
int productData::idStart = 3000;

// ================================= Main Product Class =================================
class Product
{
protected:
  vector<productData> products;
  vector<productData>::iterator ptr;

public:
  // Function to Add a product
  void addProduct(string N, double P, int Q, string cata)
  {
    productData newData;
    newData.setName(N);
    newData.setPrice(P);
    newData.setQuantity(Q);
    newData.setCatagory(cata);
    products.push_back(newData);

    cout << endl<<"Product Added Successfuly !" << endl
         << endl;
  }

  // check whether product already exit or not in stock
  bool check_existingProduct(string name)
  {
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name)
      {
        return true;
      }
    }
    return false;
  }

  // Remove a Product Function
  void removeProduct(int id)
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ptr++)
    {
      if (ptr->getID() == id)
      {
        products.erase(ptr);
        cout << endl<<"Product Removed Successfully!" << endl;
        count = 1;
        break;
      }
    }
    if (count == 0)
    {
      cout <<endl<<"Product Not Found !" << endl;
    }
  }

  // Function Display Information for Manager
  bool displayProduct()
  {
    int count = 0;

    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {

      if (count == 0)
      {
        cout << endl<<"Details of Available Products in Stock: " << endl
             << endl;
      }
      cout << "Product ID:" << ptr->getID() << "\n";
      cout << "Catagory:" << ptr->getCatagory() << endl;
      cout << "Product Name: " << ptr->getName() << endl;
      cout << "Available Quantity: " << ptr->getQuantity() << endl;
      cout << "Price: " << ptr->getPrice() << endl;
      cout << "\n";
      count = 1;
    }
    if (count == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  // display Product Details to user
  bool displayProduct_user()
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (count == 0)
      {
        cout << endl<<"Details of Available Products: " << endl
             << endl;
      }
      cout << "Catagory:" << ptr->getCatagory() << endl;
      cout << "Product Name: " << ptr->getName() << endl;
      cout << "Available Quantity: " << ptr->getQuantity() << endl;
      cout << "Price: " << ptr->getPrice() << endl;
      cout << "\n";
      count = 1;
    }
    if (count == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // Function to display details of Specific Product
  void display_specificProduct(int id)
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ptr++)
    {
      if (ptr->getID() == id)
      {
        count == 1;
        cout << "===============\tCurrent Details of the product\t===============" << endl;
        cout << "Product Name:\t" << ptr->getName() << endl;
        cout << "Product ID:\t" << ptr->getID() << endl;
        cout << "Available Quantity:\t" << ptr->getQuantity() << endl;
        cout << "Price:\t" << ptr->getPrice() << endl;
        cout << "Catagory:\t" << ptr->getCatagory() << endl;
      }
    }
    if (count == 1)
    {
      cout << endl<<"Product not found !" << endl;
    }
  }

  // Function that check the product availability
  bool isAvailable(string name, int quantity)
  {
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name && quantity <= ptr->getQuantity())
      {
        return true;
      }
    }
    return false;
  }

  // Function to change price of Product
  void changePrice(int id)
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ptr++)
    {
      if (ptr->getID() == id)
      {
        count = 1;
        cout << endl<<"Current Details of the product " << endl;
        cout << "Product Name: " << ptr->getName() << endl;
        cout << "Available Quantity: " << ptr->getQuantity() << endl;
        cout << "Price: " << ptr->getPrice() << endl;
        int price;
        cout << "Enter new price: " << endl;
        while (!(cin >> price) || price < 1)
        {
          cout << "Invalid Credentials, Enter Again:  ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        ptr->setPrice(price);
        cout << "Price Changed Successfully!" << endl;
        cout << "New Price: " << ptr->getPrice() << endl;
      }
    }
    if (count == 0)
    {
      cout << "Product not found !" << endl
           << endl;
    }
  }

  // Function to change the quantity of the product
  void changeQuantity(int id)
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ptr++)
    {
      if (ptr->getID() == id)
      {
        count = 1;
        cout << "Current Details of the product " << endl;
        cout << "Product Name: " << ptr->getName() << endl;
        cout << "Available Quantity: " << ptr->getQuantity() << endl;
        cout << "Price: " << ptr->getPrice() << endl;
        int quantity;
        cout << "Enter the updated quantity of Stock: " << endl;
        while (!(cin >> quantity) || quantity < 1)
        {
          cout << "Invalid Credentials, Enter Again:  ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        ptr->setQuantity(quantity);
        cout << endl<<"Quantity Changed Successfully!" << endl;
        cout << "New Quantity: " << ptr->getQuantity() << endl;
      }
    }
    if (count == 0)
    {
      cout << endl<<"Product not found !" << endl
           << endl;
      ;
    }
  }

  int price(string name) // Display the price
  {
    int price = 0;
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name)
      {
        price = ptr->getPrice();
        return price;
      }
    }
  }

  void updateQuantity(string name, int quantity) // Update the quantity whenever any product is sold
  {
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name)
      {
        int availableQuantity;
        availableQuantity = ptr->getQuantity() - quantity;
        // ptr->setQuantity(ptr->getQuantity() - quantity);
        ptr->setQuantity(availableQuantity);
      }
    }
  }

  int totalQuantity(string name) // total quantity of specific product
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name)
      {
        count = 1;
        return ptr->getQuantity();
      }
    }
    if (count == 0)
    {
      cout << endl<<"No item found! " << endl;
    }
  }

  bool check_itemQuantity(string name, int quantity)
  {
    int count = 0;
    for (ptr = products.begin(); ptr != products.end(); ++ptr)
    {
      if (ptr->getName() == name)
      {
        if (quantity <= ptr->getQuantity() && quantity > 0)
        {
          count = 1;
          return true;
        }
      }
    }
    if (count == 0)
    {
      return false;
    }
  }
};

//======================== Cart Class =======================================

class cartData
{
private:
  string item;
  int quantity, price;

public:
  // Setter Functions
  void setItem(string i) { item = i; }
  void setQuantity(int q) { quantity = q; }
  void addQuantity(int quan) { quantity = quan; }
  void setPrice(int p) { price = p; }

  // Getter Functions
  string getItem() { return item; }
  int getQuantity() { return quantity; }
  int getPrice() { return price; }

  // change quantity in cart
  void changeQuantity(int quantity)
  {
    this->quantity = this->quantity - quantity;
  }
};

//======================== Class for File Handling ========================
class File
{
private:
  ofstream out;

public:
  File() {}
  void openFile(string fileName)
  {
    out.open(fileName, ios::app);
  }
  void saveCresedentials(string email, double user_ID, double password)
  { // saving the login data of the user in a file
    if (out.is_open())
      out << email << "\t" << user_ID << "\t" << password << "\n";
    else
      cout << "Unable to open the file.\n";
  }
  void saveProducts(vector<cartData> items, double price);
  ~File()
  {
    out.close();
  }
};
void File::saveProducts(vector<cartData> items, double price)
{

  if (out.is_open())
  {
    out << "\t\tCart Items:\n";
    for (auto &i : items)
    {
      out << "Item Name:" << i.getItem() << "\t";
      out << "Quantity:" << i.getQuantity() << "\t";
      out << "Price:" << i.getPrice() << "\n";
    }
    out << "Total bill:" << price << "\n";
  }
  else
  {
    cout << "Unable to open the File.\n";
  }
}

//======================== Cart Class Inherited from Product Data ========================
class Cart
{
private:
  vector<cartData> items;
  vector<cartData>::iterator ptr;
  double price = 0;
  string fileName;

public:
  // Item with same name
  bool check_itemName(string item)
  {
    for (ptr = items.begin(); ptr != items.end(); ++ptr)
    {
      if (ptr->getItem() == item)
      {
        return true;
      }
    }
    return false;
  }

  // Add New item to Cart
  void addItem(Product &product, string item, int quantity)
  {
    if (product.isAvailable(item, quantity))
    {
      cartData newData;
      newData.setItem(item);
      newData.setQuantity(quantity);
      newData.setPrice(product.price(item));
      items.push_back(newData);
      cout << "Item Added to Cart Successfully !" << endl;
    }
    else
    {
      cout << "Invalid Item Name or Quantity!" << endl;
    }
  }
  void removeCart(string item) // Remove item from the cart
  {
    int count=0;
    for(ptr = items.begin(); ptr != items.end();++ptr)
    {
      if(ptr->getItem()==item)
      {
        items.erase(ptr);
        cout<<"Item Removed Successfully!"<<endl;
        count=1;
        break;
      }
    }
      if(count==0)
      {	
        cout << "Item not found!" << endl;	
      }
  }

  bool viewCart() // View the added products in the cart
  {
    int count = 0;

    for (ptr = items.begin(); ptr != items.end(); ++ptr)
    {
      if (count == 0)
      {
        cout <<endl<< "Items in Cart: " << endl;
      }
      cout << "Item: " << ptr->getItem() << endl;
      cout << "Quantity Selected: " << ptr->getQuantity() << endl
           << endl;
      count++;
    }
    if (count == 0)
    {
      return true;
    }
    return false;
  }

  // Confrim the Order and calculate the total price
  void cartConfirm(Product &product)
  {
    int price = 0;
    double password;
    cout << "Enter the password:\n";
    cin >> password;

    for (ptr = items.begin(); ptr != items.end(); ++ptr)
    {
      product.updateQuantity(ptr->getItem(), ptr->getQuantity());
      price = price + (ptr->getPrice() * ptr->getQuantity());
    }
    cout << "Total Bill: " << price << "Rs" << endl
         << endl;
    // Storing the products in the File.
    File file;
    string fileN = to_string(password) + ".txt";
    file.openFile(fileN);
    file.saveProducts(items, price);
  }

  // Clear the cart when order is confirmed by User
  void clearCart()
  {
    items.clear();
  }

  // Update the quantity of the product already exist in Cart
  void update_cartQuantity(Product product, string name, int quantity)
  {
    int count1 = 0;
    int count2 = 0;
    for (ptr = items.begin(); ptr != items.end(); ++ptr)
    {
      if (ptr->getItem() == name)
      {
        count1 = 1;
        if (product.check_itemQuantity(name, quantity))
        {
          ptr->setQuantity(quantity); // quantity updated in cart
          count2 = 1;
        }
      }
    }
    if (count1 == 0)
    {
      cout << "No product available in cart!" << endl;
    }
    if (count2 == 0 && count1 == 1)
    {
      cout << "Invalid Quantity! " << endl;
    }
    if (count2 == 1)
    {
      cout << "Updated Successfully!" << endl
           << endl;
    }
  }
};

//======================== Buyer Data Class =================================
class BuyerData
{
private:
  string email;
  int password;
  int ID;

public:
  // Constructor
  BuyerData() {}

  // setter and getter functions
  void setEmail(string email) { this->email = email; }
  void setPassword(int password) { this->password = password; }
  void setID(int ID) { this->ID = ID; }

  string getEmail() const { return email; }
  int getPassword() const { return password; }
  int getID() const { return ID; }
};

// =============================== Buyer Class ===============================
class Buyer 
{
private:
  vector<BuyerData> buyers;
  vector<BuyerData>::iterator ptr2;

public:
  Buyer() {}
  void newBuyer(const string &email, int id, int password)
  {
    BuyerData Data;
    Data.setEmail(email);
    Data.setPassword(password);
    Data.setID(id);
    buyers.push_back(Data);
    cout << endl<<"Account Successfully Registered! " << endl;
  }

  // check Buyer's ID whether it is already registered or not
  bool checkBuyer_Email(string email)
  {
    for (ptr2 = buyers.begin(); ptr2 != buyers.end(); ++ptr2)
    {
      if (ptr2->getEmail() == email)
      {
        return true;
      }
    }
    return false;
  }

  // Check Buyer's ID whether already registered or not
  bool checkBuyerID(int id)
  {
    for (ptr2 = buyers.begin(); ptr2 != buyers.end(); ++ptr2)
    {
      if (ptr2->getID() == id)
      {
        return true;
      }
    }
    return false;
  }

  // Login Check
  bool login(string email, int id, int password)
  {
    for (ptr2 = buyers.begin(); ptr2 != buyers.end(); ++ptr2)
    {
      if (ptr2->getEmail() == email && ptr2->getID() == id && ptr2->getPassword() == password)
      {
        return true;
      }
    }
    return false;
  }

  // Remove Buyer -------------------
  void removeBuyer(int id)
  {
    int count = 0;
    for (ptr2 = buyers.begin(); ptr2 != buyers.end(); ++ptr2)
    {
      if (ptr2->getID() == id)
      {
        buyers.erase(ptr2);
        cout << endl<<"Buyer Removed Successfully!" << endl;
        count = 1;
        break;
      }
    }
    if (count == 0)
    {
      cout << endl<<"Buyer not found!" << endl;
    }
  }

  // Display All Buyers ---------------------
  void displayBuyers()
  {
    int i = 0;

    for (ptr2 = buyers.begin(); ptr2 != buyers.end(); ++ptr2)
    {
      if (i == 0)
      {
        cout <<endl<< "Buyers Registered: " << endl
             << endl;
      }
      cout << "========\tBuyer " << i + 1 << "\t========" << endl;
      cout << "Email: " << ptr2->getEmail() << endl;
      cout << "CNIC: " << ptr2->getID() << endl;
      cout << "Password: " << ptr2->getPassword() << endl
           << endl;
      i++;
    }
    if (i != 0)
    {
      cout << endl<<"Total Registered buyers are: " << i << endl;
    }
    if (i == 0)
    {
      cout << "== No Buyer Registered Yet ! ==" << endl
           << endl;
    }
  }

  // Display Menu to Customer when succesffuly login
  void display_customerMenu(Product &product)
  {
    int choice, quantity;
    string name;
    char decision;
    Cart cart;
    do
    {
      cout << "===========\tWelcome To Our Store\t===========" << endl
           << endl;
      cout << "1. Available Products" << endl;
      cout << "2. Add Product to Cart" << endl;
      cout << "3. Remove from Cart" << endl;
      cout << "4. View Cart" << endl;
      cout << "5. Change quantity of existing Product in cart" << endl;
      cout << "6. Log Out" << endl;
      cout << "Note: Logging out without Confirming cart will clear cart!" << endl;
      cout << "Enter your choice(1-5): " << endl;

      while (!(cin >> choice) || choice < 1 || choice > 6)
      {
        cout << "Invalid Credentials, Enter Again(1-5):  ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

      switch (choice)
      {
      case 1: // Display available products to user
        if (product.displayProduct_user())
        {
          cout << "No products available yet! " << endl;
        }
        cout << endl;
        break;

      case 2: // User add the product to its cart
        cout << "Enter name of item: " << endl;
        getline(cin >> ws, name);

        if (cart.check_itemName(name))
        {
          cout << endl<<"Item already exist! You can update its quantity. " << endl
               << endl;
        }
        else
        {
          cout << "Enter quantity: " << endl;
          while (!(cin >> quantity) || quantity < 1)
          {
            cout << "Invalid Credentials, Enter Again:  ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
          cart.addItem(product, name, quantity);
        }

        cout << endl;
        break;

      case 3: // User can also remove the products from the Cart
        if (cart.viewCart())
        {
          cout << "No item yet in the Cart!" << endl;
        }
        else
        {
          cout << "Enter name of item you want to Remove: " << endl;
          getline(cin >> ws, name);
          cart.removeCart(name);
        }
        cout << endl;
        break;

      case 4: // User view the products in the cart
        if (cart.viewCart())
        {
          cout << "No item yet in the Cart!" << endl;
        }
        else
        {
          cout << "Confirm Cart?(y/n): " << endl;
          cin >> decision;
          if (decision == 'y' || decision == 'Y')
          {
            cart.cartConfirm(product);
            cart.clearCart();
          }
        }
        cout << endl;
        break;

      case 5: // User update the quantity of existing product in cart
        cout << "Enter the name of the product: " << endl;
        getline(cin >> ws, name);
        if (cart.check_itemName(name))
        {
          if (cart.check_itemName(name))
          {
            cout << "Enter the updated quantity: ";
            while (!(cin >> quantity) || quantity < 1)
            {
              cout << "Invalid Credentials, Enter Again:  ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cart.update_cartQuantity(product, name, quantity);
          }
        }
        else
        {
          cout << "No products available yet in cart! " << endl;
        }
        cout << endl;
        break;

      case 6: // Logout
        cout << "Logging Out" << endl;
        for (int i = 0; i < 3; i++)
        {
          cout << " . " << endl;
          sleep(1);
        }
        break;

      default:
        cout << "Error !" << endl;
      }
    } while (choice != 6);
  }
};

// =============================== Manager Class ===============================
class Manager
{
private:
  string email;
  string id;
  int password;

public:
  Manager()
  {
    email = "manager123@gmail.com"; // manager email fr login each time
    id = "manager123";              // manager's id
    password = 1234;                // manager's password
  }

  // getter functions
  string getEmail() { return email; }
  int getPassword() { return password; }
  string getID() { return id; }

  void managerMenu(Buyer &buyer, Product &product); // Declaration
};

// Defination of Memeber Function "ManagerMenu"
void Manager::managerMenu(Buyer &buyer, Product &product)
{
  int choice;
  string name;
  string catgory;
  double price;
  int quantity, counter;
  cout << "===========\tWelcome Manager\t===========" << endl;

  do
  {
    cout << "1. Add new Product " << endl;
    cout << "2. Remove existing Product" << endl;
    cout << "3. View All Product Details" << endl;
    cout << "4. Remove Buyer " << endl;
    cout << "5. Display Details of All Buyers" << endl;
    cout << "6. Change Price of specific Product " << endl;
    cout << "7. Change Quantity of specific Product" << endl;
    cout << "8. Log Out " << endl;
    cout << "Enter your choice (1-8): " << endl;
    while (!(cin >> choice) || choice < 1 || choice > 8)
    {
      cout << "Please enter a valid choice (1-8): ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int id;

    switch (choice)
    {
    case 1: // Add a new product
      cout << "Enter the following details of the product: " << endl;
      cout << "Name: ";
      getline(cin >> ws, name);
      if (product.check_existingProduct(name))
      {
        cout << endl<<"Error! Product Already Exit. " << endl<<endl;
        break;
      }
      else
      {
        cout << "Price: ";
        while (!(cin >> price) || price < 1)
        {
          cout << "invalid Credentials, Enter Again: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Quantity: ";
        while (!(cin >> quantity) || quantity < 1)
        {
          cout << "Invalid Credentials, Enter Again: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Catagory: ";
        getline(cin >> ws, catgory);
      }

      product.addProduct(name, price, quantity, catgory);
      break;

    case 2: // Remove a Product
      cout << "Enter product ID: " << endl;
      while (!(cin >> id) || id < 1)
      {
        cout << "Invalid Credentials, Enter Again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      product.removeProduct(id);
      break;

    case 3: // View All product details
      if (product.displayProduct())
      {
        cout << "No yet product is added to the stock! " << endl;
        break;
      }
      cout << endl;
      break;

    case 4: // Remove Buyer
      cout << "Enter Buyer's CNIC: " << endl;
      while (!(cin >> id) || id < 1)
      {
        cout << "Invalid Credentials, Enter Again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      buyer.removeBuyer(id);
      break;

    case 5: // Display All Buyers Info
      buyer.displayBuyers();
      break;

    case 6: // Change price
      cout << "Enter Product ID: ";
      while (!(cin >> id) || id < 3000)
      {
        cout << "Invalid Credentials, Enter Again ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      product.changePrice(id);
      break;

    case 7: // quantity of the product
      cout << "Enter Product ID: ";
      while (!(cin >> id) || id < 3000)
      {
        cout << "Invalid Credentials, Enter Again:  ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      product.changeQuantity(id);
      break;

    case 8: // Logout
      cout << "Logging Out" << endl;
      for (int i = 0; i < 3; i++)
      {
        cout << " . " << endl;
        sleep(1);
      }
      break;
    }
  } while (choice != 8);
}

// Random NUmber Generating Function
int randno()
{
  sleep(2);
  int num;
  srand(time(NULL));
  num = rand() % 10000;
  if (num < 1000)
  {
    num = num + 1000;
  }
  cout << "Your password is generating " << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << " ." << endl;
    sleep(1);
  }
  cout << "Password: " << num << ". Remember for next time login!" << endl;

  return num;
}

// ======================= Main Menu Start ================================
int main(void)
{
  int choice, choice1, choice2;
  string email;
  string ID;
  int user_ID;
  int password;
  Manager manager;
  Product product;
  Buyer buyer;
  Cart c;
  cout<<endl;
  cout << "================= Welcome to Invetory Management System =================" << endl;
  do
  {
    cout << "1. Login as Manager." << endl;
    cout << "2. Login / Register as a Buyer." << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";

    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
      cout << "Please enter a valid choice (1-3): ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int count = 0;
    switch (choice)
    {
    case 1: //======================= Login as a Manager ========================
      cout << endl<<"Enter following details: " << endl;
      do
      {
        cout << "Email: ";
        getline(cin >> ws, email);
        if (email.find('@') != string::npos) // check for @ symbol in email
        {
          if (email == manager.getEmail())
          {
            count = 0; // count variable set to 0 for the number of times user enters the email
            cout << endl<<"The Email you entered is correct!\n"<<endl;
            do
            {
              cout << "Enter ID: ";
              getline(cin >> ws, ID);
              if (ID == manager.getID())
              {
                count = 0;
                do
                {
                  cout << "Enter password: ";
                  cin >> password;
                  if (password == manager.getPassword())
                  {
                    cout << endl<<endl<<"You're successfully LoggedIn as a Manager !" << endl;
                    manager.managerMenu(buyer, product); // Move to Managers Menu
                  }
                  else
                  {
                    cout << endl<<"Incorrect password!, Enter again "<<endl;
                    count++;
                  }
                  if (count == 2)
                  {
                    cout << "Your entered password for insufficient times!" << endl;
                    break;
                  }

                } while (manager.getPassword() != password);
                // cout << "You're successfully LoggedIn as a Manager !" << endl;
              }
              else
              {
                cout << endl<<"Incorrect ID, Enter again! "<<endl;
                count++;
              }
              if (count == 2)
              {
                cout << endl<<"Your entered ID for insufficient times!" << endl;
                break;
              }

            } while (manager.getID() != ID);
          }
          else
          {
            cout<<endl<<"Incorrect Email!, Enter Again: "<<endl;
          }
          if (count == 2)
          {
            cout << "Your entered email for insufficient times!" << endl;
            break;
          }
        }
        else
        {
          cout << endl<<"The email you entered is not correct!\n"<<endl;
          cout << "Enter the email again.\n";
        }
      } while (manager.getEmail() != email);
      break;

    case 2: //======================= Login / Register as a Buyer ========================
      do
      {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " << "\n";
        while (!(cin >> choice1) || choice1 < 1 || choice1 > 3)
        {
          cout << "Invalid Credentials, Enter Again:  ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice1 == 1) // Registeration Process Starts
        {
          cout << "Enter Email: ";
          getline(cin >> ws, email);

          if (buyer.checkBuyer_Email(email)) // check buyer's ID
          {
            cout << "This email is already Registered! Enter another email for Registeration of Login " << endl;
            continue;
          }

          if (email.find('@') != string::npos)
          {
            cout << "Enter your CNIC (5 digits): ";
            while (!(cin >> user_ID) || user_ID > 99999 || user_ID < 10000)
            {
              cout << "Invalid Credentials, Enter Again:  ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            while (buyer.checkBuyerID(user_ID))
            {
              cout << "CNIC already registered! Enter your CNIC Again (5 digits): ";
              while (!(cin >> user_ID) || user_ID > 99999 || user_ID < 10000)
              {
                cout << "Invalid Credentials, Enter Again:  ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
              }
            }
            cout << "Registeration Successful!" << endl;

            password = randno();
            buyer.newBuyer(email, user_ID, password);
            File file;
            string fileName = to_string(password) + ".txt";
            file.openFile(fileName);
            file.saveCresedentials(email, user_ID, password);
          }
          else
          {
            cout << "The email you entered is not correct.\n";
          }
        }
        else if (choice1 == 2) // Login Process Starts
        {
          cout << "Enter your email: ";
          getline(cin >> ws, email);
          if (email.find('@') != string::npos)
          {

            cout << "Enter your ID: ";
            while (!(cin >> user_ID) || user_ID > 99999 || user_ID < 0)
            {
              cout << "Invalid Credentials, Enter Again:  ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter Password: ";
            while (!(cin >> password) || password < 0)
            {
              cout << "Invalid Credentials, Enter Again:  ";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            if (buyer.login(email, user_ID, password))
            {
              cout << "You've successfully Logged In !" << endl;
              buyer.display_customerMenu(product);
            }
            else
            {
              cout << "Invalid email, ID, or password" << endl;
            }
          }
        }
        else if (choice1 == 3) // Exit
        {
          break;
        }
        else
        {
          cout << "Invalid choice! Enter again (1-3): ";
        }
      } while (choice1 != 3);
      break;

    case 3:
      break;
    }
  } while (choice != 3);
  cout << endl
       << "==================\tGood Bye :)\t==================" << endl;
  return 0;
}

/* =========================== Program Completed Successfully =======================*/