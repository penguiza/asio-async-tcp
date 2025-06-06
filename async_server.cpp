#include <iostream>
#include <asio.hpp>

asio::io_context io;

void start_read(std::shared_ptr<asio::ip::tcp::socket> socket, std::shared_ptr<std::array<char, 1024>> buffer)
{
	socket->async_read_some(asio::buffer(*buffer), [socket, buffer](std::error_code ec, std::size_t len) {
		if (!ec) {
			std::string message(buffer->data(), len);
			std::cout << "Client: " << message << '\n';
			start_read(socket, buffer);
		}
		});
}

void start_accept(asio::ip::tcp::acceptor& acceptor)
{
	auto socket = std::make_shared<asio::ip::tcp::socket>(io);
	acceptor.async_accept(*socket, [&acceptor, socket](std::error_code ec) {
		if (!ec) {
			std::cout << "Connected to clinet!" << std::endl;
			auto buffer = std::make_shared<std::array<char, 1024>>();
			start_read(socket, buffer);
		}
	start_accept(acceptor);
		});
}

int main()
{

	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 1234);
	asio::ip::tcp::acceptor acceptor(io, endpoint);

	start_accept(acceptor);
	std::cout << "Listening on port 1234" << std::endl;
	io.run();


}