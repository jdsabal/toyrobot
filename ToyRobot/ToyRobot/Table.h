#ifndef __TABLE_H
#define __TABLE_H

namespace ToyRobot
{
	class Table
	{
	public:
		Table(const Table&) = delete;
		Table(Table&&) = delete;
		Table& operator=(const Table&) = delete;
		Table& operator=(Table&&) = delete;

		static Table& instance()
		{
			static Table _instance;
			return _instance;
		}

		bool insideTable(unsigned x, unsigned y);
	private:
		Table() = default;
		~Table() = default;

		static const unsigned int X_MAX = 5;
		static const unsigned int Y_MAX = 5;
	};
}

#endif // !__TABLE_H

