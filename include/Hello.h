#ifndef __HELLO_H__
#define __HELLO_H__
#include <string>
#include <vector>


struct Receipt_item {
    std::string barcode;
    std::string name;
    size_t price;
    size_t amount;

    bool operator==(const Receipt_item& rhs) const;
    bool operator!=(const Receipt_item& rhs) const;
};

std::string BuildReceipt(const std::vector<std::string>& barcodes);
std::string PrintReceipt(std::vector<Receipt_item> goods_after_count, std::string total_price);
std::vector<Receipt_item> CountItems(std::vector<std::string> barcodes);
std::string GetTotalPrice(std::vector<Receipt_item> receipt_items);

#endif
