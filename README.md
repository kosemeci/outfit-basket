**[TR]:**


# Kıyafet Sipariş Yönetim Sistemi

Bu proje, kullanıcıların kıyafet siparişi verebileceği ve yöneticilerin sistemi yönetebileceği bir konsol uygulamasıdır. Kullanıcılar kıyafet seçebilir, sepet oluşturabilir ve siparişlerini tamamlayabilir. Yöneticiler ise ürün ekleyebilir, kullanıcıları yönetebilir ve sistem kayıtlarını inceleyebilir.

## Özellikler

- **Kullanıcı İşlemleri:**
  - Yeni kullanıcı kaydı
  - Sisteme giriş ve hesap yönetimi
  - Şifre değiştirme
  - Sepet görüntüleme ve sipariş tamamlama

- **Yönetici İşlemleri:**
  - Yeni yönetici veya kurye ekleme
  - Ürün kategorilerine kıyafet ekleme
  - Sipariş faturalarını görüntüleme
  - Kullanıcılara indirim kodu tanımlama
  - Şikayet ve önerileri inceleme

## Kullanım

1. Programı başlatın ve giriş ekranından bir işlem seçin.
2. Kullanıcı olarak giriş yaparak ürünlere göz atabilir ve alışveriş yapabilirsiniz.
3. Yönetici olarak sistem kayıtlarını ve ürünleri yönetebilirsiniz.

## Teknik Detaylar

- **Programlama Dili:** C++
- **Dosya Yönetimi:** `fstream` kütüphanesi
- **Gizli Giriş:** `_getch` ile parola gizliliği
- **Sınıflar:** Kullanıcı, Yönetici, Kıyafet, Kurye, Sepet

## Gereksinimler

- C++ derleyici (örn. GCC, Visual Studio)
- `conio.h` desteği olan bir platform

---

**[ENG]:**

```markdown
# Clothing Order Management System

This project is a console application that allows users to order clothes and enables administrators to manage the system. Users can browse clothes, create carts, and complete their orders, while administrators can add products, manage users, and review system logs.

## Features

- **User Operations:**
  - Register new users
  - Login and manage accounts
  - Change password
  - View cart and complete orders

- **Admin Operations:**
  - Add new administrators or couriers
  - Add clothes to product categories
  - View order invoices
  - Assign discount codes to users
  - Review complaints and suggestions

## Usage

1. Start the program and select an operation from the menu.
2. Login as a user to browse products and shop.
3. Login as an administrator to manage records and products.

## Technical Details

- **Programming Language:** C++
- **File Management:** Using `fstream` library
- **Hidden Input:** Password security with `_getch`
- **Classes:** User, Admin, Clothing, Courier, Cart

## Requirements

- C++ compiler (e.g., GCC, Visual Studio)
- A platform supporting `conio.h`
