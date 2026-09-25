// Implement a function that takes a vector<tuple<string,int,double>> representing (product_name, quantity, unit_price) 
// and returns a tuple<double, string, int> of (total_inventory_value, most_valuable_product_name, total_item_count) 
// where total inventory value = sum of quantity * unit_price across all products, most valuable = highest quantity * unit_price single product, 
// and total item count = sum of all quantities.

#include<bits/stdc++.h>
using namespace std;

typedef tuple<string, int, double> Product;

tuple<double, string, int> foo(const vector<Product>& input) {
    double total_invetory_value = 0;
    string most_valuable_product_name;
    int total_item_count = 0;

    double most_valuable_product_value = 0;

    for (auto [product_name, quantity, unit_price] : input) {
        total_item_count += quantity;
        double product_value = quantity * unit_price;

        total_invetory_value += product_value;

        if (product_value > most_valuable_product_value) {
            most_valuable_product_name = product_name;
            most_valuable_product_value = product_value;
        }
            
    }

    return make_tuple(total_invetory_value, most_valuable_product_name, total_item_count);
}

int main() {
    vector<Product> v1 = {
        make_tuple("apple",10,0.5), 
        make_tuple("laptop",2,999.99), 
        make_tuple("pen",50,0.1)
    };
    double iv;
    string pn;
    int ic;
    tie(iv, pn, ic) = foo(v1);
    cout << "Total value: " << iv << '\n';
    cout << "Most valuable product: " << pn << '\n';
    cout << "Total Items count: " << ic << '\n';


    return 0;
}