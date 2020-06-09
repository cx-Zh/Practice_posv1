#include "Hello.h"

#include <iostream>

struct Good {
    std::string barcode;
    std::string name;
    size_t price;
};

std::vector<Good> goods = {
    {"ITEM000001", "Apple", 460},
    {"ITEM000003", "Cup", 100},
    {"ITEM000005", "Banana", 300},
};

std::string BuildReceipt(const std::vector<std::string>& barcodes)
{
    std::vector<Receipt_item> receipt_items = CountItems(barcodes);
    std::string total_price = GetTotalPrice(receipt_items);
    std::string receipt = PrintReceipt(receipt_items, total_price);
    return receipt;
}

std::string PrintReceipt(std::vector<Receipt_item> receipt_item, std::string total_price){
    std::string receipt = "Receipts:\n----------------\n";
    for (auto & iter : receipt_item){
        receipt += iter.barcode + ", " + iter.name + ", x" + std::to_string(iter.amount) + ", " +
                   std::to_string(iter.price * iter.amount) + "\n";
    }
    receipt += "\n----------------\nTOTAL:     " + total_price;
    return receipt;
}

std::vector<Receipt_item> CountItems(std::vector<std::string> barcodes){
    std::vector<Receipt_item> receipt_items;
    for (auto & barcode : barcodes){
        bool find_flag = false;
        for(auto & item : receipt_items){
            if(item.barcode == barcode){
                find_flag = true;
                item.amount += 1;
                break;
            }
        }
        if (!find_flag){
            for(auto & good : goods){
                if(good.barcode == barcode){
                    Receipt_item receipt_item_temp = {good.barcode, good.name,good.price,1};
                    receipt_items.push_back(receipt_item_temp);
                    break;
                }
            }
        }
    }
//    for(auto & item : receipt_items){
//        std::cout<< item.barcode<<item.price<<item.name<<item.amount<<std::endl;
//    }
    return receipt_items;
}

std::string GetTotalPrice(std::vector<Receipt_item> receipt_items){
    size_t total_price = 0;
    for(auto & item : receipt_items){
        total_price += item.price * item.amount;
    }
    return std::to_string(total_price);
}

bool Receipt_item::operator==(const Receipt_item& rhs) const
{
    return barcode == rhs.barcode && name == rhs.name && price == rhs.price && amount == rhs.amount;
}
bool Receipt_item::operator!=(const Receipt_item& rhs) const
{
    return !(rhs == *this);
}
