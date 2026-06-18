template <typename type_key = int, typename type_value = int>
class HashMap
{
protected:
    static const int default_size = 8;
    constexpr static const double factor_rehash = 0.75;
    struct Node
    {
        type_key key;
        type_value value;
        bool state;
        bool alive;
        Node()
        {
            state = true;
            alive = false;
        }
        Node(pair<type_key, type_value>& a)
        {
            key = a.first;
            value = a.second;
            state = true;
            alive = true;
        }
        Node(const type_key& key_, const type_value& value_)
        {
            key = key_;
            value = value_;
            state = true;
            alive = true;
        }

        bool operator !=(Node a) { return (key != a.key || value != a.value); }
        bool operator ==(Node a) { return (key == a.key && value == a.value); }
    };
    vector<Node> arr;
    int size_alive;
    int size_dead;

    int get_hash(string key)
    {
        int hash = 0, d = 179, mod = 1e9 + 7;
        for (int i = 0; i < key.size(); ++i)
            hash = (hash * d + key[i]) % mod;
        return hash;
    }
    int get_hash(int key) { return key; }
    int get_index (type_key key)
    {
        int hash = get_hash(key);
        return hash % arr.size();
    }

    void Rehash(int new_size)
    {
        size_alive = 0;
        size_dead = 0;
        vector<Node> arr2(new_size);
        for (int i = 0; i < arr2.size(); ++i)
            arr2[i] = Node();
        std::swap(arr, arr2);
        for (int i = 0; i < arr2.size(); ++i)
            if (arr2[i].alive && arr2[i].state)
                Add(arr2[i]);
        arr2.clear();
    }
    void Resize() { Rehash(arr.size() * 2); }

    int Find(const type_key& key)
    {
        int h1 = get_index(key);
        int h2 = 1e6 + 3;
        int i = 0;
        while (arr[h1].alive && i < arr.size())
        {
            if (arr[h1].key == key && arr[h1].state)
                return h1;
            h1 = (h1 + h2) % arr.size();
            ++i;
        }
        return -1;
    }
    int Remove(const type_key& key)
    {
        int k = Find(key);
        if (k == -1) return k;
        arr[k].state = false;
        --size_alive;
        ++size_dead;
        return k;
    }
    bool Add(const Node& value)
    {
        int k = Find(value.key);
        if (k != -1)
        {
            arr[k] = value;
            return true;
        }
        if (size_alive + size_dead + 1 > int(factor_rehash * arr.size()))
            Resize();
        if (size_dead > size_alive)
            Rehash(arr.size());
        int h1 = get_index(value.key);
        int h2 = 1e6 + 3;
        int i = 0;
        int first_deleted = -1;
        while (arr[h1].alive && i < arr.size())
        {
            if (arr[h1] == value && arr[h1].state)
                return false;
            if (!arr[h1].state && first_deleted == -1)
                first_deleted = h1;
            h1 = (h1 + h2) % arr.size();
            ++i;
        }
        if (first_deleted == -1)
            arr[h1] = value;
        else
        {
            arr[first_deleted] = value;
            --size_dead;
        }
        ++size_alive;
        return true;
    }
public:
    HashMap<type_key, type_value> ()
    {
        size_alive = 0;
        size_dead = 0;
        arr = vector<Node> (default_size);
    }
    HashMap<type_key, type_value> (vector<pair<type_key, type_value> > a)
    {
        size_alive = 0;
        size_dead = 0;
        arr = vector<Node> (default_size);
        for (int i = 0; i < a.size(); ++i)
            Add(Node(a[i]));
    }
    ~HashMap<type_key, type_value>() { arr.clear(); }

    pair<type_key, type_value> find(type_key key)
    {
        int k = Find(key);
        if (k != -1) return make_pair(arr[k].key, arr[k].value);
        return pair<type_key, type_value> ();
    }
    pair<type_key, type_value> erase(type_key key)
    {
        int k = Remove(key);
        if (k != -1) return make_pair(arr[k].key, arr[k].value);
        return pair<type_key, type_value> ();
    }

    type_value operator [](type_key key)
    {
        int k = Find(key);
        if (k == -1) return arr[0].value;
        return arr[k].value;
    }
};

//https://leetcode.com/problems/design-hashmap/ - for check