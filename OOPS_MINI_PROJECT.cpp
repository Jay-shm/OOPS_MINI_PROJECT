#include <iostream>
#include <vector>
#include <string>

//Author: Jay Rane

using namespace std;

class Event {
public:
    Event() {}
    Event(const string& name, const string& date, const string& time, int availableSeats, double price_INR)
        : name(name), date(date), time(time), availableSeats(availableSeats), price(price_INR) {}

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

class User {
public:
    User() {}
    User(const string& username, const string& email, const string& password, const string& userID)
        : username(username), email(email), password(password), userID(userID) {}

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

    void displayUserInfo() const {
        cout << "User Name: " << username << endl;
        cout << "Email: " << email << endl;
        cout << "User ID: " << userID << endl;
    }

    bool checkCredentials(const string& username, const string& password) const {
        return (username == this->username) && (password == this->password);
    }

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

class Booking {
public:
    Booking() {}
    Booking(const class User& user, const class Event& event, int numberOfTickets)
        : user(user), event(event), numberOfTickets(numberOfTickets) {}

    class User getUser() const {
        return user;
    }

    class Event getEvent() const {
        return event;
    }

    int getNumberOfTickets() const {
        return numberOfTickets;
    }

    void setUser(const class User& user) {
        this->user = user;
    }

    void setEvent(const class Event& event) {
        this->event = event;
    }

    void setNumberOfTickets(int numberOfTickets) {
        this->numberOfTickets = numberOfTickets;
    }

    double calculateTotalPrice() const {
        double eventPrice = event.getPrice();
        return static_cast<double>(numberOfTickets) * eventPrice;
    }

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

void User::addBooking(const class Booking& booking) {
    bookings.push_back(booking);
}

vector<class Booking> User::getBookings() const {
    return bookings;
}

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

void formatUserBookingDetails(const User& user, const Booking& booking) {
    cout << "---------------- Booking Details ----------------" << endl;
    user.displayUserInfo();
    booking.displayBookingDetails();
    cout << "-----------------------------------------------" << endl;
}

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

    Event event1("Concert", "2023-11-10", "19:30", 1000, 4500.0);
    Event event2("Theater Show", "2023-11-15", "20:00", 500, 6000.0);
    Event event3("Sports Game", "2023-11-20", "15:00", 2000, 3000.0);
    Event event4("Art Exhibition", "2023-11-25", "14:00", 300, 2500.0);
    Event event5("Movie Premiere", "2023-11-30", "18:30", 400, 350.0);
    Event event6("Comedy Show", "2023-12-05", "20:15", 600, 800.0);
    Event event7("Dance Performance", "2023-12-10", "16:45", 250, 1500.0);
    Event event8("Workshop", "2023-12-15", "10:00", 100, 1200.0);
    Event event9("Food Festival", "2023-12-20", "12:00", 800, 500.0);
    Event event10("Tech Conference", "2023-12-25", "09:30", 400, 1800.0);

    events.push_back(event1);
    events.push_back(event2);
    events.push_back(event3);
    events.push_back(event4);
    events.push_back(event5);
    events.push_back(event6);
    events.push_back(event7);
    events.push_back(event8);
    events.push_back(event9);
    events.push_back(event10);

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
                string username, email, password, userID;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your email: ";
                cin >> email;
                cout << "Enter your password: ";
                cin >> password;
                cout << "Enter your user ID: ";
                cin >> userID;

                users.push_back(User(username, email, password, userID));
                cout << "Registration successful!" << endl;
                break;
            }

            case 2: {
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
                                cout << "Booking History:" << endl;
                                vector<Booking> userBookings = getUserBookings(users[userID]);
                                for (int i = 0; i < userBookings.size(); ++i) {
                                    formatUserBookingDetails(users[userID], userBookings[i]);
                                }
                                break;
                            }

                            case 4: {
                                formatAvailableEvents(events);
                                break;
                            }

                            case 5: {
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
