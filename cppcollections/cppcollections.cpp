#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <queue>
#include <iostream>
namespace py = pybind11;
using namespace std;

class bxjj {
public:
	int* data2, length;
	int father(int x) {
		if (data2[x] < 0)return x;
		data2[x] = father(data2[x]);
		return data2[x];
	}
	bxjj(int l) {
		length = l;
		data2 = new int[length];
		for (int i = 0; i < length; i++)data2[i] = -1;
	}
	~bxjj() {
		delete[] data2;
	}
	void hb(int a, int b) {
		a = father(a);
		b = father(b);
		if (a == b)return;
		if (data2[a] < data2[b]) {
			data2[a] += data2[b];
			data2[b] = a;
		}
		else {
			data2[b] += data2[a];
			data2[a] = b;
		}
	}
	bool cha(int a, int b) {
		return father(a) == father(b);
	}
	vector<vector<int>> result() {
		unordered_map<int,vector<int>> ret;
		vector<vector<int>> rret;
		for (int i = 0; i < length; ++i) {
			int f = father(i);
			if (ret.count(f))ret[f].push_back(i);
			else ret[f] = {i};
		}
		for (auto& i : ret) {
			rret.emplace_back(i.second);
		}
		return rret;
	}
};

PYBIND11_MODULE(cppcollections, m) {
	py::class_<queue<int>>(m, "QueueInt")
		.def(py::init<>())
		.def(py::init<queue<int>>())
		.def("push", py::overload_cast<int&&>(&queue<int>::push))
		.def("push", py::overload_cast<const int&>(&queue<int>::push))
		.def("pop", &queue<int>::pop)
		.def("empty", &queue<int>::empty)
		.def("back", py::overload_cast<>(&queue<int>::back))
		.def("front", py::overload_cast<>(&queue<int>::front))
		.def("size", &queue<int>::size)
		.def("__len__", &queue<int>::size)
		.def("swap", &queue<int>::swap)
		.def("__str__", [](const queue<int>& self) {
		if (self.size() == 0)return string("QueueInt[]");
		else if (self.size() == 1)return "QueueInt[" + to_string(self.front()) + "]";
		else if (self.size() == 2)return "QueueInt[" + to_string(self.front()) + ", " + to_string(self.back()) + "]";
		return "QueueInt[" + to_string(self.front()) + ",<<" + to_string(self.size()-2) + ">>," + to_string(self.back()) + "]";
			});
	py::class_<priority_queue<int>>(m, "Priority_Queue_Max")
		.def(py::init<>())
		.def(py::init<priority_queue<int>>())
		.def("from_vector", [](priority_queue<int>& x, const vector<int>& y) {
				priority_queue<int> tmp(y.begin(), y.end());
				tmp.swap(x);
			})
		.def("empty", &priority_queue<int>::empty)
		.def("push", py::overload_cast<int&&>(&priority_queue<int>::push))
		.def("push", py::overload_cast<const int&>(&priority_queue<int>::push))
		.def("pop", &priority_queue<int>::pop)
		.def("top", &priority_queue<int>::top)
		.def("size", &priority_queue<int>::size)
		.def("__len__", &priority_queue<int>::size)
		.def("swap", &priority_queue<int>::swap);
	py::class_<priority_queue<int,vector<int>,greater<int>>>(m, "Priority_Queue_Min")
		.def(py::init<>())
		.def(py::init<priority_queue<int, vector<int>, greater<int>>>())
		.def("from_vector", [](priority_queue<int, vector<int>, greater<int>>& x, const vector<int>& y) {
				priority_queue<int, vector<int>, greater<int>> tmp(y.begin(), y.end());
				tmp.swap(x);
			})
		.def(py::init<>())
		.def("empty", &priority_queue<int, vector<int>, greater<int>>::empty)
		.def("push", py::overload_cast<int&&>(&priority_queue<int, vector<int>, greater<int>>::push))
		.def("push", py::overload_cast<const int&>(&priority_queue<int, vector<int>, greater<int>>::push))
		.def("pop", &priority_queue<int, vector<int>, greater<int>>::pop)
		.def("top", &priority_queue<int, vector<int>, greater<int>>::top)
		.def("size", &priority_queue<int, vector<int>, greater<int>>::size)
		.def("__len__", &priority_queue<int, vector<int>, greater<int>>::size)
		.def("swap", &priority_queue<int, vector<int>, greater<int>>::swap);
	py::class_<bxjj>(m, "bxjj")
		.def(py::init<int>(), py::arg("length"))
		.def("hb", &bxjj::hb, py::arg("a"), py::arg("b"))
		.def("cha", &bxjj::cha, py::arg("a"), py::arg("b"))
		.def("result", &bxjj::result)
		.def("father", &bxjj::father, py::arg("x"))
		.def("__str__", [](const bxjj& self) {
				string ret = "bxjj[";
				if (self.length == 0)return ret + "]";
				for (int i = 0; i < self.length - 1; ++i) {
					ret += to_string(self.data2[i]) + ", ";
				}
				return ret + to_string(self.data2[self.length - 1]) + "]";
			})
		.def("__len__", [](const bxjj& self) {
				return self.length;
			})
		.def_readonly("length", &bxjj::length);
}