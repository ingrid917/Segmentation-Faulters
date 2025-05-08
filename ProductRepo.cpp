//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "ProductRepo.h"
#include <algorithm>

bool ProductRepo::productExists(const string& id) const {
    for (const auto& p : products) {
        if (p.getId() == id) return true;
    }
    return false;
}

bool ProductRepo::addProduct(const Product& product) {
    if (productExists(product.getId()))
        return false;  // ID must be unique
    products.push_back(product);
    return true;
}

const vector<Product>& ProductRepo::getAllProducts() const {
    return products;
}

vector<Product> ProductRepo::getAvailableProductsSortedByPrice() const {
    vector<Product> result;
    for (const auto& p : products) {
        if (p.getStock() > 0) {
            result.push_back(p);
        }
    }
    sort(result.begin(), result.end(),
              [](const Product& a, const Product& b) {
                  return a.getPrice() < b.getPrice();
              });
    return result;

}
vector<Product> loadInitialProducts() {
    vector<Product> products;


    string id1 = "P001", name1 = "Milk";
    string id2 = "P002", name2 = "Bread";
    string id3 = "P003", name3 = "Apples";
    string id4 = "P004", name4 = "Cheese";
    string id5 = "P005", name5 = "Tomatoes";
    string id6 = "P006", name6 = "Eggs";
    string id7 = "P007", name7 = "Butter";
    string id8 = "P008", name8 = "Chicken";
    string id9 = "P009", name9 = "Juice";
    string id10 = "P010", name10 = "Pasta";


    products.emplace_back(id1, name1, 4.50, 100);
    products.emplace_back(id2, name2, 2.00, 50);
    products.emplace_back(id3, name3, 3.75, 80);
    products.emplace_back(id4, name4, 5.90, 40);
    products.emplace_back(id5, name5, 2.80, 60);
    products.emplace_back(id6, name6, 3.20, 30);
    products.emplace_back(id7, name7, 4.10, 25);
    products.emplace_back(id8, name8, 8.90, 20);
    products.emplace_back(id9, name9, 6.50, 45);
    products.emplace_back(id10, name10, 3.00, 150);

    return products;
}