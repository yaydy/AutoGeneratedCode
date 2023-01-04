#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Function prototype for the message handler function
void handle_message(char* message);

int main(void) {
  CURL* curl;
  CURLcode res;

  // Initialize the cURL library
  curl_global_init(CURL_GLOBAL_ALL);

  // Set up a cURL handle
  curl = curl_easy_init();
  if (curl) {
    // Set the URL for the bot's message endpoint
    curl_easy_setopt(curl, CURLOPT_URL, "https://discordapp.com/api/v6/channels/{channel_id}/messages");

    // Set the HTTP method to POST
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    // Set the message handler function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_message);

    // Set the bot's authorization token
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Authorization: Bot {bot_token}");

    // Set the content type to application/json
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Content-Type: application/json");

    // Set the request body to a JSON payload containing the message
    char* payload = "{\"content\": \"Hello, world!\"}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);

    // Send the message
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    // Clean up
    curl_easy_cleanup(curl);
  }

  // Clean up the cURL library
  curl_global_cleanup();
  return 0;
}

// Message handler function
void handle_message(char* message) {
  // Print the message to the console
  printf("Received message: %s\n", message);
}
