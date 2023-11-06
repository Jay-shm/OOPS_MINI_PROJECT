#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to manage all the event details
class Event {
public:
    Event() {}

    // Constructor to initialize event details
    Event(const string& name, const string& date, const string& time, int availableSeats, double price_INR)
        : name(name), date(date), time(time), availableSeats(availableSeats), price(price_INR) {}

    // Getter methods for event attributes
    string getName() const {
        return name;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    double getPrice() const {
        return price;
    }

    // Setter methods for modifying event attributes
    void setName(const string& name) {
        this->name = name;
    }

    void setDate(const string& date) {
        this->date = date;
    }

    void setTime(const string& time) {
        this->time = time;
    }

    void setAvailableSeats(int availableSeats) {
        this->availableSeats = availableSeats;
    }

    void setPrice(double price_INR) {
        this->price = price_INR;
    }

    // Method to display event details
    void displayEventDetails() const {
        cout << "Event Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Price: " << price << " INR" << endl;
    }

private:
    string name;
    string date;
    string time;
    int availableSeats;
    double price;
};

// Class to manage all the User details
class User {
public:
    User() {}

    // Constructor to initialize user details
    User(const string& username, const string& email, const string& password, const string& userID)
        : username(username), email(email), password(password), userID(userID) {}

    // Getter methods for user attributes
    string getUsername() const {
        return username;
    }

    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    string getUserID() const {
        return userID;
    }

    // Setter methods for modifying user attributes
    void setUsername(const string& name) {
        username = name;
    }

    void setEmail(const string& email) {
        this->email = email;
    }

    void setPassword(const string& password) {
        this->password = password;
    }

    void setUserID(const string& userID) {
        this->userID = userID;
    }

    // Method to display user details
    void displayUserInfo() const {
        cout << "User Name: " << username << endl;
        cout << "Email: " << email << endl;
        cout << "User ID: " << userID << endl;
    }

    // Method to check user credentials
    bool checkCredentials(const string& username, const string& password) const {
        return (username == this->username) && (password == this->password);
    }

    // Method to update user profile
    void updateProfile(const string& newUsername, const string& newPassword) {
        username = newUsername;
        password = newPassword;
    }

    void addBooking(const class Booking& booking);
    vector<class Booking> getBookings() const;

private:
    string username;
    string email;
    string password;
    string userID;
    vector<class Booking> bookings;
};

// Class to process all the bookings
class Booking {
public:
    Booking() {}

    // Constructor to initialize booking details
    Booking(const class User& user, const class Event& event, int numberOfTickets)
        : user(user), event(event), numberOfTickets(numberOfTickets) {}

    // Getter methods for booking attributes
    class User getUser() const {
        return user;
    }

    class Event getEvent() const {
        return event;
    }

    int getNumberOfTickets() const {
        return numberOfTickets;
    }

    // Setter methods for modifying booking attributes
    void setUser(const class User& user) {
        this->user = user;
    }

    void setEvent(const class Event& event) {
        this->event = event;
    }

    void setNumberOfTickets(int numberOfTickets) {
        this->numberOfTickets = numberOfTickets;
    }

    // Method to calculate the total price for the booking
    double calculateTotalPrice() const {
        double eventPrice = event.getPrice();
        return static_cast<double>(numberOfTickets) * eventPrice;
    }

    // Method to display booking details
    void displayBookingDetails() const {
        cout << "Booking Details:" << endl;
        user.displayUserInfo();
        event.displayEventDetails();
        cout << "Number of Tickets: " << numberOfTickets << endl;
        cout << "Total Price: " << calculateTotalPrice() << " INR" << endl;
    }

    bool bookEvent(class User& user, class Event& event, int numberOfTickets);
    vector<class Booking> getUserBookings(const class User& user) const;

private:
    class User user;
    class Event event;
    int numberOfTickets;
};

// Method to add a booking to the user's bookings
void User::addBooking(const class Booking& booking) {
    bookings.push_back(booking);
}

// Method to get user's bookings
vector<class Booking> User::getBookings() const {
    return bookings;
}

// Function to book an event
bool bookEvent(User& user, Event& event, int numberOfTickets) {
    if (event.getAvailableSeats() >= numberOfTickets) {
        Booking newBooking(user, event, numberOfTickets);
        user.addBooking(newBooking);
        event.setAvailableSeats(event.getAvailableSeats() - numberOfTickets); // Update available seats
        return true;
    } else {
        return false;
    }
}

// Function to get a user's bookings
vector<class Booking> getUserBookings(const User& user) {
    vector<class Booking> userBookings = user.getBookings();
    vector<class Booking> filteredBookings;

    for (const Booking& booking : userBookings) {
        if (booking.getUser().getUserID() == user.getUserID()) {
            filteredBookings.push_back(booking);
        }
    }

    return filteredBookings;
}

// Function to format user booking details
void formatUserBookingDetails(const User& user, const Booking& booking) {
    cout << "---------------- Booking Details ----------------" << endl;
    user.displayUserInfo();
    booking.displayBookingDetails();
    cout << "-----------------------------------------------" << endl;
}

// Function to format available events
void formatAvailableEvents(const vector<Event>& events) {
    cout << "---------------- Available Events ----------------" << endl;
    for (int i = 0; i < events.size(); ++i) {
        cout << "Event " << i + 1 << ":" << endl;
        events[i].displayEventDetails();
        cout << "-----------------------------------------------" << endl;
    }
}

int main() {
    vector<User> users;
    vector<Event> events;

    // Initialize event objects
    Event event1("Concert", "2023-11-10", "19:30", 1000, 4500.0);
    Event event2("Theater Show", "2023-11-15", "20:00", 500, 6000.0);
    // ... (similarly initialize more events)

    // Push events to the events vector
    events.push_back(event1);
    events.push_back(event2);
    // ... (push more events)

    int choice;
    while (true) {
        cout << "----------------------------------------------------" << endl;
        cout << "           Online Ticket Booking System" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1. Register as a new user" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // User registration
                string username, email, password, userID;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your email: ";
                cin >> email;
                cout << "Enter your password: ";
                cin >> password;
                cout << "Enter your user ID: ";
                cin >> userID;

                // Create and add a new user to the users vector
                users.push_back(User(username, email, password, userID));
                cout << "Registration successful!" << endl;
                break;
            }

            case 2: {
                // User login
                string UUsername, PPassword;
                cout << "Enter your username: ";
                cin >> UUsername;
                cout << "Enter your password: ";
                cin >> PPassword;

                int loggedInUserID = -1;
                for (int i = 0; i < users.size(); ++i) {
                    if (users[i].checkCredentials(UUsername, PPassword)) {
                        loggedInUserID = i;
                        break;
                    }
                }

                if (loggedInUserID == -1) {
                    cout << "Invalid username or password. Please try again." << endl;
                } else {
                    int userID = loggedInUserID;
                    bool isUserLoggedIn = true;

                    while (isUserLoggedIn) {
                        cout << "----------------------------------------------------" << endl;
                        cout << "           Welcome, " << users[userID].getUsername() << "!" << endl;
                        cout << "----------------------------------------------------" << endl;
                        cout << "1. Update profile" << endl;
                        cout << "2. Book an event" << endl;
                        cout << "3. View booking history" << endl;
                        cout << "4. View available events" << endl;
                        cout << "5. Log out" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1: {
                                // Update user profile
                                string newUsername, newPassword;
                                cout << "Enter your new username: ";
                                cin >> newUsername;
                                cout << "Enter your new password: ";
                                cin >> newPassword;

                                users[userID].updateProfile(newUsername, newPassword);
                                cout << "Profile updated successfully!" << endl;
                                break;
                            }

                            case 2: {
                                // Booking an event
                                int eventId;
                                cout << "Choose an event to book:" << endl;
                                for (int i = 0; i < events.size(); ++i) {
                                    cout << "Event " << i + 1 << ":" << endl;
                                    events[i].displayEventDetails();
                                    cout << "-----------------------------------------------" << endl;
                                }
                                cout << "Enter the event number: ";
                                cin >> eventId;
                                eventId--;

                                if (eventId < 0 || eventId >= events.size()) {
                                    cout << "Invalid event selection. Please try again." << endl;
                                } else {
                                    int numberOfTickets;
                                    cout << "Enter the number of tickets to book: ";
                                    cin >> numberOfTickets;

                                    if (bookEvent(users[userID], events[eventId], numberOfTickets)) {
                                        cout << "Event booked successfully!" << endl;
                                    } else {
                                        cout << "Event booking failed. No available seats or insufficient tickets." << endl;
                                    }
                                }
                                break;
                            }

                            case 3: {
                                // View booking history
                                cout << "Booking History:" << endl;
                                vector<Booking> userBookings = getUserBookings(users[userID]);
                                for (int i = 0; i < userBookings.size(); ++i) {
                                    formatUserBookingDetails(users[userID], userBookings[i]);
                                }
                                break;
                            }

                            case 4: {
                                // View available events
                                formatAvailableEvents(events);
                                break;
                            }

                            case 5: {
                                // Log out
                                cout << "Logged out." << endl;
                                isUserLoggedIn = false;
                                break;
                            }

                            default: {
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        }
                    }
                }
                break;
            }

            case 3: {
                // Exit the program
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
