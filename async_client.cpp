#include <iostream>
#include <asio.hpp>

asio::io_context io;

void start_write(std::shared_ptr<asio::ip::tcp::socket> socket)
{
	std::string message;
	std::cout << "You: ";
	std::getline(std::cin, message);

	auto msg = std::make_shared<std::string>(message);
	asio::async_write(*socket, asio::buffer(*msg),[socket, msg](std::error_code ec, std::size_t len) {
		if (!ec) {
			start_write(socket);
		}
		});
}




int main()
{
	std::string server_ip;
	std::cout << "Enter server IP address:(127.0.0.1 for local host) ";
	std::getline(std::cin, server_ip);

	asio::ip::tcp::resolver resolver(io);
	auto endpoint = resolver.resolve(server_ip, "1234");

	auto socket = std::make_shared<asio::ip::tcp::socket>(io);

	asio::async_connect(*socket, endpoint, [socket](std::error_code ec, asio::ip::tcp::endpoint) {
		if (!ec) {
			std::cout << "Connected to server" << std::endl;

			start_write(socket);
		}
		});

	io.run();

}
