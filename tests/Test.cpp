#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;

TEST(Pos, Case1)
{
    std::string receipt = BuildReceipt({"ITEM000001"});
    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x1, 460

----------------
TOTAL:     460)";
    EXPECT_THAT(receipt, Eq(expect));
}

TEST(PrintReceipt, should_return_receipt_with_goods_after_count)
{
    std::string total_price = "920";
    std::vector<Receipt_item> goods_after_count = {{"ITEM000001", "Apple", 460, 2}};
    std::string receipt = PrintReceipt(goods_after_count, total_price);
    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x2, 920

----------------
TOTAL:     920)";
    EXPECT_THAT(receipt, Eq(expect));
}

TEST(CountItems, should_get_receipt_items_from_barcodes)
{
    std::vector<std::string> barcodes = {"ITEM000001", "ITEM000003", "ITEM000001", "", "aaa111"};
    std::vector<Receipt_item> receipt_items = CountItems(barcodes);
    const std::vector<Receipt_item> expect ={
        {"ITEM000001", "Apple", 460, 2},
        {"ITEM000003", "Cup", 100, 1}
    };
    EXPECT_THAT(receipt_items, Eq(expect));
}

TEST(GetTotalPrice, should_get_total_price_from_receipt_items)
{
    std::vector<Receipt_item> receipt_items= {
        {"ITEM000001", "Apple", 460, 2},
        {"ITEM000003", "Cup", 100, 1}
    };
    std::string total_price = GetTotalPrice(receipt_items);
    std::string expect = "1020";
    EXPECT_THAT(total_price, Eq(expect));
}