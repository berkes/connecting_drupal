# Be sure to restart your server when you modify this file.

# Your secret key for verifying cookie session data integrity.
# If you change this key, all old sessions will become invalid!
# Make sure the secret is at least 30 characters and all random, 
# no regular words or you'll be exposed to dictionary attacks.
ActionController::Base.session = {
  :key         => '_spree_session',
  :secret      => '9ba50660925e997aa0eb60715f7bf0c6ce1be79b7d70d840bd335a38a845188eb78471fa3ea3df85f9e262aa5a26feddbd1a0632ee8713be69a3284e8e92b8ca'
}

# Use the database for sessions instead of the cookie-based default,
# which shouldn't be used to store highly confidential information
# (create the session table with "rake db:sessions:create")
# ActionController::Base.session_store = :active_record_store