# Online Ticket Booking System

Welcome to the Online Ticket Booking System GitHub repository. This C++ program simulates an online ticket booking system, allowing users to register, log in, book events, and manage their profiles. This README will guide you through the code and its components.

## 📁 File Structure

- **main.cpp**: This is the main source code file containing the entire program.
- **README.md**: You are currently reading this file, which provides an explanation of the code.

## 🚀 How It Works

The program is organized into three main classes:

1. **Event Class** (Represents an Event):
   - Properties: Event name, date, time, available seats, and price.
   - Methods: Display event details.

2. **User Class** (Represents a User):
   - Properties: Username, email, password, user ID, and a list of bookings.
   - Methods: Display user information, check credentials, update profile, add booking, get bookings.

3. **Booking Class** (Represents a Booking):
   - Properties: User, Event, and the number of tickets.
   - Methods: Display booking details, calculate total price.

The program's main features include user registration, user login, profile management, event booking, booking history viewing, and event listing.

## 🔧 Setup and Usage

1. **Compile the Code**: Ensure you have a C++ development environment set up. Compile the code using your compiler of choice. For example, using g++:
   
   ```bash
   g++ main.cpp -o ticket_booking
   ```

2. **Run the Program**: Execute the compiled program:
   
   ```bash
   ./ticket_booking
   ```

3. **Follow the Menu**: The program will display a menu for users to navigate. Follow the on-screen prompts to register, log in, and use the system.

## 📝 Code Explanation

- **Classes**: The code defines three classes: `Event`, `User`, and `Booking`. These classes represent events, users, and bookings and contain properties and methods for managing them.

- **Functions**: The program includes several functions, such as `bookEvent`, `getUserBookings`, `formatUserBookingDetails`, and `formatAvailableEvents`, to perform actions like booking events and formatting output.

- **Data Storage**: Users and events are stored in vectors to manage user data and available events.

- **Main Function**: The `main` function is the program's entry point and provides the user interface. Users can register, log in, update their profiles, book events, view booking history, and see available events.

## 💡 Additional Information

- Error handling is implemented to handle invalid inputs and ensure that events are not overbooked.
- The code includes comments to explain each part of the program.

## 📜 License

This code is provided under the [MIT License](LICENSE). Feel free to use, modify, and distribute it.

---

Feel free to customize this README to include any additional information, contact details, or specific instructions for your GitHub repository.
