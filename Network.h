#ifndef NETWORK_H
#define NETWORK_H

#include <stdexcept>
#include <string>

// Representation: CSR (compressed sparse row).
// Each user owns a contiguous slice of the friends array, and row_starts marks
// where each slice begins.
class Network {
private:
    int num_users;
    int num_connections;
    int *row_starts;  // length: num_users + 1
    int *friends;     // length: 2 * num_connections for undirected edges

    void copy_from(const Network &other);
    void clear();
    void validate_user(int user_id) const;
    void validate_pair(int user_id1, int user_id2) const;

public:
    Network(const std::string &filename);
    ~Network();

    Network(const Network &other);
    Network &operator=(const Network &other);

    int get_num_users() const;
    int get_num_connections() const;

    bool is_friend(int user_id1, int user_id2) const;

    int num_friends(int user_id) const;
    int num_friends_of_friends(int user_id) const;
    int num_mutual_friends(int user_id1, int user_id2) const;
    int most_popular_user() const;
};

#endif
