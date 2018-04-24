#include <iostream>
#include <initializer_list>
#include <iomanip>

template <typename T>
class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		T key;

		node_t() : left(nullptr), right(nullptr), key(0)
		{

		}

		~node_t()
		{
			delete left;
			delete right;
		}

		node_t* FindMax(node_t* root)
		{
			if (root == nullptr)
				return nullptr;

			while (root->right != nullptr)
			{
				root = root->right;
			}
			return root;
		}


		bool find_node(T value)
		{
			if (value == key)
			{
				return true;
			}

			if (value > this->key && this->right)
			{
				return this->right->find_node(value);
			}
			if (value < this->key && this->left)
			{
				return this->left->find_node(value);
			}
		}

		void print_(std::ostream & stream, T set) const {
			if (this == nullptr)
			{
				std::cout << "Binary tree is empty";

			}
			else
			{
				if (this->right != nullptr) {
					this->right->print_(stream, set + 5);
				}

				std::cout << std::setw(set + 5) << std::setfill('-') << key << std::endl;

				if (this->left != nullptr) {
					this->left->print_(stream, set + 5);
				}
			}

		}

		friend bool operator==(node_t const & lhs, node_t const & rhs)
		{
			return lhs.key == rhs.key
				&& ((lhs.left == 0 && rhs.left == 0)
					|| (lhs.left != 0 && rhs.left != 0 && *lhs.left == *rhs.left))
				&& ((lhs.right == 0 && rhs.right == 0)
					|| (lhs.right != 0 && rhs.right != 0 && *lhs.right == *rhs.right));
		}

		node_t * deleteNode(node_t* root, T key)
		{
			if (root == nullptr)
				return root;
			else if (key < root->key)
			{
				root->left = deleteNode(root->left, key);
			}
			else if (key > root->key)
			{
				root->right = deleteNode(root->right, key);
			}
			else
			{
				if (root->right == nullptr && root->left == nullptr)
				{
					delete root;
					root = nullptr;
				}
				else if (root->right == nullptr)
				{
					node_t * temp = root;
					root = root->left;
					delete temp;
				}
				else if (root->left == nullptr)
				{
					node_t * temp = root;
					root = root->right;
					delete temp;
				}
				else
				{
					node_t * temp = FindMax(root->left);
					root->key = temp->key;
					root->left = deleteNode(root->left, temp->key);
				}
			}
			return root;
		}

	};
private:
	node_t * root_;
public:
	tree_t() noexcept;
	tree_t(std::initializer_list<T> keys);
	auto operator==(tree_t const & other) const;
	void insert(T key);
	bool remove(T key);
	bool find(T key) const;
	void print(std::ostream & stream) const;
};

template <typename T>
tree_t<T>::tree_t(std::initializer_list<T> keys)
{
	if (root_ != nullptr)
	{
		root_ = nullptr;
		for (auto & value : keys)
		{
			root_->insert(value);
		}
	}
	else
	{
		for (auto & value : keys)
		{
			root_->insert(value);
		}
	}
}

template <typename T>
auto tree_t<T>::operator==(tree_t const & other) const
{
	if (root_ == 0 && other.root_ == 0)
	{
		return true;
	}
	else if (root_ != 0 && other.root_ != 0 && *root_ == *other.root_)
	{
		return false;
	}

}

template <typename T>
tree_t<T>::tree_t() noexcept : root_(nullptr)
{

}

template <typename T>
bool tree_t<T>::find(T key) const
{
	return root_ ? root_->find_node(key) : false;
}

template <typename T>
void tree_t<T>::insert(T key)
{
	node_t * tree = new node_t;
	tree->key = key;
	tree->left = tree->right = 0;

	node_t * buff = root_;
	node_t * temp = root_;

	while (temp)
	{
		buff = temp;
		if (key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (!buff)
	{
		root_ = tree;
	}
	else
	{
		if (key < buff->key)
			buff->left = tree;
		else
			buff->right = tree;
	}
}


template <typename T>
void tree_t<T>::print(std::ostream & stream) const
{
	root_->print_(stream, 0);
}

template <typename T>
bool tree_t<T>::remove(T key)
{
	node_t * temp = root_;
	root_ = root_->deleteNode(root_, key);

	if (temp == root_)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	return 0;
}
