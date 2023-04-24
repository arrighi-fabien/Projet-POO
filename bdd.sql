CREATE TABLE customer(
   id_customer INT IDENTITY (1, 1),
   first_name VARCHAR(40) NOT NULL,
   last_name VARCHAR(40) NOT NULL,
   birth_date DATE NOT NULL,
   first_purchase DATE,
   PRIMARY KEY(id_customer)
);

CREATE TABLE country(
   id_country INT IDENTITY (1, 1),
   country_name VARCHAR(50) NOT NULL,
   PRIMARY KEY(id_country),
   UNIQUE(country_name)
);

CREATE TABLE city(
   id_city INT IDENTITY (1, 1),
   city_name VARCHAR(50) NOT NULL,
   id_country INT NOT NULL,
   PRIMARY KEY(id_city),
   FOREIGN KEY(id_country) REFERENCES country(id_country)
);

CREATE TABLE Address(
   id_address INT IDENTITY (1, 1),
   address VARCHAR(200),
   additional_address VARCHAR(100),
   postal_code VARCHAR(10) NOT NULL,
   id_city INT NOT NULL,
   PRIMARY KEY(id_address),
   FOREIGN KEY(id_city) REFERENCES city(id_city)
);

CREATE TABLE orders(
   id_order INT IDENTITY (1, 1),
   order_reference VARCHAR(20) NOT NULL,
   delivery_date DATE NOT NULL,
   issue_date DATETIME NOT NULL,
   pay_date DATETIME,
   id_customer INT NOT NULL,
   id_shipping_address INT NOT NULL,
   id_billing_address INT NOT NULL,
   PRIMARY KEY(id_order),
   UNIQUE(order_reference),
   FOREIGN KEY(id_customer) REFERENCES customer(id_customer),
   FOREIGN KEY(id_shipping_address) REFERENCES Address(id_address),
   FOREIGN KEY(id_billing_address) REFERENCES Address(id_address)
);

CREATE TABLE payment_method(
   id_payment_method INT IDENTITY (1, 1),
   payment_method VARCHAR(50),
   PRIMARY KEY(id_payment_method)
);

CREATE TABLE item_category(
   id_item_category INT IDENTITY (1, 1),
   item_category_name VARCHAR(50) NOT NULL,
   PRIMARY KEY(id_item_category),
   UNIQUE(item_category_name)
);

CREATE TABLE bill(
   id_bill INT IDENTITY (1, 1),
   bill_order_reference VARCHAR(20) NOT NULL,
   bill_first_name VARCHAR(40) NOT NULL,
   bill_last_name VARCHAR(40) NOT NULL,
   bill_customer_number VARCHAR(50),
   bill_issue_date DATETIME NOT NULL,
   bill_billing_address VARCHAR(400),
   bill_shipping_address VARCHAR(400),
   PRIMARY KEY(id_bill),
   UNIQUE(bill_order_reference)
);

CREATE TABLE bill_item(
   id_bill_item INT IDENTITY (1, 1),
   bill_item_reference VARCHAR(50) NOT NULL,
   bill_item_name VARCHAR(50) NOT NULL,
   bill_item_category_name VARCHAR(50) NOT NULL,
   PRIMARY KEY(id_bill_item),
   UNIQUE(bill_item_reference)
);

CREATE TABLE payment(
   id_payment INT IDENTITY (1, 1),
   payment_date DATETIME NOT NULL,
   payment_amount DECIMAL(15,2) NOT NULL,
   id_payment_method INT NOT NULL,
   id_order INT NOT NULL,
   PRIMARY KEY(id_payment),
   FOREIGN KEY(id_payment_method) REFERENCES payment_method(id_payment_method),
   FOREIGN KEY(id_order) REFERENCES orders(id_order)
);

CREATE TABLE item(
   id_item INT IDENTITY (1, 1),
   item_reference VARCHAR(50) NOT NULL,
   item_name VARCHAR(50) NOT NULL,
   in_stock INT NOT NULL,
   restocking_level INT NOT NULL,
   id_item_category INT NOT NULL,
   PRIMARY KEY(id_item),
   UNIQUE(item_reference),
   FOREIGN KEY(id_item_category) REFERENCES item_category(id_item_category)
);

CREATE TABLE item_price(
   id_item_price INT IDENTITY (1, 1),
   vat_rate DECIMAL(15,2) NOT NULL,
   item_price_et DECIMAL(15,2) NOT NULL,
   date_change DATETIME NOT NULL,
   id_item INT NOT NULL,
   PRIMARY KEY(id_item_price),
   FOREIGN KEY(id_item) REFERENCES item(id_item)
);

CREATE TABLE staff(
   id_staff INT IDENTITY (1, 1),
   first_name VARCHAR(40) NOT NULL,
   last_name VARCHAR(40) NOT NULL,
   hiring_date DATE NOT NULL,
   id_address INT NOT NULL,
   id_manager INT,
   PRIMARY KEY(id_staff),
   FOREIGN KEY(id_address) REFERENCES Address(id_address),
   FOREIGN KEY(id_manager) REFERENCES staff(id_staff)
);

CREATE TABLE billed_to(
   id_customer INT,
   id_address INT,
   PRIMARY KEY(id_customer, id_address),
   FOREIGN KEY(id_customer) REFERENCES customer(id_customer),
   FOREIGN KEY(id_address) REFERENCES Address(id_address) ON DELETE CASCADE
);

CREATE TABLE delivered_to(
   id_customer INT,
   id_address INT,
   PRIMARY KEY(id_customer, id_address),
   FOREIGN KEY(id_customer) REFERENCES customer(id_customer),
   FOREIGN KEY(id_address) REFERENCES Address(id_address) ON DELETE CASCADE
);

CREATE TABLE order_contain(
   id_order_contain INT IDENTITY (1, 1),
   id_order INT,
   id_item INT,
   id_item_price INT,
   quantity INT NOT NULL,
   commercial_discount DECIMAL(15,2) NOT NULL,
   PRIMARY KEY(id_order_contain),
   FOREIGN KEY(id_order) REFERENCES orders(id_order),
   FOREIGN KEY(id_item) REFERENCES item(id_item),
   FOREIGN KEY(id_item_price) REFERENCES item_price(id_item_price)
);

CREATE TABLE bill_contain(
   id_bill INT,
   id_bill_item INT,
   bill_item_price_et DECIMAL(15,2) NOT NULL,
   bill_vat_rate DECIMAL(15,2) NOT NULL,
   bill_quantity VARCHAR(50) NOT NULL,
   bill_commercial_discount DECIMAL(15,2),
   PRIMARY KEY(id_bill, id_bill_item),
   FOREIGN KEY(id_bill) REFERENCES bill(id_bill),
   FOREIGN KEY(id_bill_item) REFERENCES bill_item(id_bill_item)
);

ALTER TABLE orders
ADD CONSTRAINT df_issue_date
DEFAULT GETDATE() FOR issue_date

ALTER TABLE item_price
ADD CONSTRAINT df_date_change
DEFAULT GETDATE() FOR date_change
